#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
// ������������ ��� �������������� � ����������� ��������
////////////////////////////////////////////////////////////////////////////////////////////
/*
// Checker ����� ������������� ��� ��� ��� ��������:
AC = Accepted = ������� ����� ���������� ��������� �� ������ �����
WA = Wrong Answer = ������� ����� ������������ ��������� �� ������ �����
PE = Presentation Error = ������ ������� �������� ������
// ��������� �������� checker �� ����� �������������
NO = No verdict = ������� �����������
CE = Compilation Error = ������ ����������
ML = Memory Limit Exceeded = ��������� ����������� �� ������
TL = Time Limit Exceeded = ��������� ����������� �� ������� ������ RE = Runtime Error = ������ ������� ���������� ���������
IL = Idle Limit Exceeded = ��������� ����� ������� (�����������) ���������
DE = Deadly Error = ������ ����������� �������
*/
enum verdict { NO = 1, AC, WA, CE, ML, TL, RE, IL, PE, DE };
class result {
    private:
        FILE * bur;
    public:
        enum ext_cls { NO = 1, VERDICT, MESSAGE, TIME, MEMORY };

        result(bool read = false) 
        {
            if (read) fopen_s(&bur, "..//result.txt", "r"); 
            else fopen_s(&bur, "..//result.txt", "w");
        } 
        
        ~result()
        {
            fclose(bur);
        }

        void write_type(ext_cls t)
        {
            fwrite(&t, sizeof(t), 1, bur);
        }

        void write_verdict(verdict v) 
        {
            write_type(ext_cls::VERDICT); 
            fwrite(&v, sizeof(v), 1, bur);
        }
        // �������� ��������� �� checker'a ������������.
        //   ��������, ��� ������� ������, ��� ��������.
        // ������������ ������ ��������� ����� � ����� ����������
        void write_message(string str) 
        {
            write_type(ext_cls::MESSAGE); 
            int l = str.size(); 
            fwrite(&l, sizeof(l), 1, bur);
            fwrite(&str[0], sizeof(str[0]), l, bur);
        }
        // �������� ����������� ������� ����� ������ ��������� ���������,
        //   ����������� � ������� before_code
        // x ����� ����������� 100 �� = 10 ^ (-7) ���
        void write_time(long long x) {
            write_type(ext_cls::TIME);
            fwrite(&x, sizeof(x), 1, bur);
        }
        // �������� ����������� �������, ������ ������������� ���������� ���������
        void write_memory(unsigned long long x) {
            write_type(ext_cls::MEMORY);
            fwrite(&x, sizeof(x), 1, bur);
        }
} checker_result;

int main(int argc, char * argv[]) {
    FILE * f1;
    double res_time;
    int n;
    int* res;

    std::string fileName = "array";
    if (argc == 2) {
        fileName = argv[1];
    }

    freopen_s(&f1, ("..//" + fileName + ".out").c_str(), "rb", stdin);
    fread(&res_time, sizeof(res_time), 1, stdin);
    fread(&n, sizeof(n), 1, stdin);
    res = new int[n];
    fread(res, sizeof(*res), n, stdin);
    
    bool IsCorrect = true;
    for (int i = 1; i < n; i++)
    {
        if (res[i - 1] > res[i])
        {
            IsCorrect = false;
            break;
        }
    }

    if (IsCorrect) {
        checker_result.write_message("AC. Array sort.");
        checker_result.write_verdict(verdict::AC);
    }
    else
    {
        checker_result.write_message("WA. Array not sort.");
        checker_result.write_verdict(verdict::WA);
    }

    checker_result.write_time(res_time * 1e7);
    fclose(f1);
    return 0;
}