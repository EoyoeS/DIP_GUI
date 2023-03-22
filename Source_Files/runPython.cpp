#include "function.h"
#include <Python.h>

using namespace std;

void runPython(vector<int>& location_x, vector<int>& location_y)
{
    // ����python.exe��·��
    Py_SetPythonHome(L"C:\\Users\\19941\\AppData\\Local\\Programs\\Python\\Python310");
    Py_Initialize(); //����Py_Initialize()���г�ʼ��
    if (!Py_IsInitialized())
    {
        cout << "��ʼ��ʧ��!" << endl;
    }
    else
    {
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('.\\Py_Files')"); //ָ��face.py���ڵ�Ŀ¼

        PyObject* pModule = nullptr;  // ����ģ��face.py
        // PyObject* pFunc = nullptr; // ��������find_face
        PyObject* pFuncl = nullptr;   // ��������find_face_landmark

        pModule = PyImport_ImportModule("face"); //������Ҫ���õ��ļ���face.py
        if (pModule == NULL)
        {
            cout << "û�ҵ���Python�ļ�" << endl;
        }
        else
        {
            // pFunc = PyObject_GetAttrString(pModule, "find_face");//������Ҫ���õĺ�����
            pFuncl = PyObject_GetAttrString(pModule, "find_face_landmarks");

            // ������C++��String�����ڸ�ʽ�ϵ����⣡
            PyObject* args = Py_BuildValue("(s)", ".\\Resource_Files\\1.jpg");//��python����������ֵ
            // PyObject* face = PyObject_CallObject(pFunc, args);  // �沿���ο�
            PyObject* mark = PyObject_CallObject(pFuncl, args);    // ���ú�������ȡ�������б�
            PyObject* x = nullptr;
            PyObject* y = nullptr;

            for (int n = 0; n < int(PyList_GET_SIZE(mark)); n++)
            {
                PyObject* location = PyList_GetItem(mark, n);
                x = PyTuple_GetItem(location, 0);
                y = PyTuple_GetItem(location, 1);
                int int_x = 1;
                int int_y = 1;

                PyArg_Parse(x, "i", &int_x);
                PyArg_Parse(y, "i", &int_y);
                location_x.push_back(int_x);  // �������x����
                location_y.push_back(int_y);  // �������y����
            }
        }
        Py_Finalize();//����Py_Finalize�������Py_Initialize���Ӧ�ġ�
    }
}