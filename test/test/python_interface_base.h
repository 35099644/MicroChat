#pragma once
#include <map>
#include "python.h"
using namespace std;

//ʹ�ÿ���̨��ʾlog
#define USE_CONSOLE

#define PY_FREE(x)		if(x)	Py_DECREF(x)

class CPyModule
{
public:
	PyObject*						m_pModule = NULL;	//pythonģ��
	map<CStringA, PyObject*>		m_FuncMap;			//������
};


class CPythonBase
{
public:
	CPythonBase();
	~CPythonBase();
	
	//����ģ��
	PyObject *ImportModule(LPCSTR szModuleName);

	//ע��python���������ò���
	BOOL RegisterPythonFunction(LPCSTR szModuleName, LPCSTR szFuncName);

	//ִ��Python����
	PyObject *CallObject(LPCSTR szModuleName, LPCSTR szFuncName, LPCSTR szArgsFormat = NULL, ...);

protected:
	PyObject *ParseResult(PyObject *p, LPCSTR szKey, LPCSTR szArgsFormat, void *pRet);
private:
	//��ʼ��Python���������
	void Init();

	map<CStringA, CPyModule*>	m_map;
};

