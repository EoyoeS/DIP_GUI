#include "function.h"
#include <vector>
#include <QTextBrowser>

using namespace std;

void showVector(vector<int>& x, bool console)
{
    // ����һ���ַ�����
    std::stringstream ss;

    // �������е�Ԫ����ӵ��ַ�������
    for (int i = 0; i < x.size(); ++i) 
        ss << x[i] << "\n";

    // ��ȡ�ַ������е��ַ���
    std::string str = ss.str();

    // ���ַ�������ΪText Browser���ı�
    QTextBrowser textBrowser;
    textBrowser.setText(QString::fromStdString(str));
    textBrowser.show();

    // ��ϵͳΪ����̨ʱֱ�����������̨
    if (console)
    {
        for (vector<int>::iterator iter = x.begin(); iter != x.end(); iter++)
        {
            cout << *iter << endl;
        } 
    }
    
}