#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <math.h>

static PyObject *method_Len(PyObject *self, PyObject *args)
{
    PyObject *ElementOfVector;
    PyListObject *Vector;
    Py_ssize_t n;
    int i;
    double VectorLen = 0;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!", &PyList_Type, &Vector))
    {
        PyErr_SetString(PyExc_TypeError, "Argument must be a list.");
        return NULL;
    }

    n = PyList_Size(Vector);

    for(i=0; i<n; i++)
    {
        ElementOfVector = PyList_GetItem(Vector, i);

        if(PyLong_Check(ElementOfVector))
        {
            VectorLen = VectorLen + pow(PyLong_AsDouble(ElementOfVector), 2);
        }
        else if(PyFloat_Check(ElementOfVector))
        {
            VectorLen = VectorLen + pow(PyFloat_AsDouble(ElementOfVector), 2);
        }
        else
        {
            PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
            return NULL;
        }

    }

    return Py_BuildValue("d", pow(VectorLen, 1./2.));
}

static PyObject *method_Normalize(PyObject *self, PyObject *args)
{
    PyObject *ElementOfVector;
    PyListObject *Vector, *NormalizedVector = PyList_New(0);
    Py_ssize_t n;
    int i;
    double VectorLen = 0;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!", &PyList_Type, &Vector))
    {
        PyErr_SetString(PyExc_TypeError, "Argument must be a list.");
        return NULL;
    }

    n = PyList_Size(Vector);
    VectorLen = PyFloat_AsDouble(method_Len(NULL, args));//method_Test(NULL, PyList_AsTuple(Vector));

    for(i=0; i<n; i++)
    {
        ElementOfVector = PyList_GetItem(Vector, i);

        if(VectorLen == 0.)
        {
            PyList_Append(NormalizedVector, PyFloat_FromDouble(VectorLen));
        }
        else if(PyLong_Check(ElementOfVector))
        {
            PyList_Append(NormalizedVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfVector)/VectorLen));
        }
        else if(PyFloat_Check(ElementOfVector))
        {
            PyList_Append(NormalizedVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfVector)/VectorLen));
        }
        else
        {
            PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
            return NULL;
        }

    }

    return NormalizedVector;
}

static PyObject *method_VxR(PyObject *self, PyObject *args)
{
    PyObject *ElementOfVector;
    PyListObject *Vector, *NewVector = PyList_New(0);
    Py_ssize_t n;
    int i;
    double R;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!d", &PyList_Type, &Vector, &R))
    {
        return NULL;
    }

    n = PyList_Size(Vector);

    for(i=0; i<n; i++)
    {

        ElementOfVector = PyList_GetItem(Vector, i);

        if(PyLong_Check(ElementOfVector))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfVector)*R));
        }
        else if(PyFloat_Check(ElementOfVector))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfVector)*R));
        }
        else
        {
            PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
            return NULL;
        }

    }

    return NewVector;
}

static PyObject *method_VplusV(PyObject *self, PyObject *args)
{
    PyObject *ElementOfVector1, *ElementOfVector2;
    PyListObject *Vector1, *Vector2, *NewVector = PyList_New(0);
    Py_ssize_t n1, n2;
    int i;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Vector1, &PyList_Type, &Vector2))
    {
        return NULL;
    }

    n1 = PyList_Size(Vector1);
    n2 = PyList_Size(Vector2);

    if(n1 != n2)
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Vectros is different!");
        return NULL;
    }

    for(i=0; i<n1; i++)
    {

        ElementOfVector1 = PyList_GetItem(Vector1, i);
        ElementOfVector2 = PyList_GetItem(Vector2, i);

        if(PyLong_Check(ElementOfVector1) && PyLong_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfVector1) + PyLong_AsDouble(ElementOfVector2)));
        }
        else if(PyLong_Check(ElementOfVector1) && PyFloat_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfVector1) + PyFloat_AsDouble(ElementOfVector2)));
        }
        else if(PyFloat_Check(ElementOfVector1) && PyLong_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfVector1) + PyLong_AsDouble(ElementOfVector2)));
        }
        else if(PyFloat_Check(ElementOfVector1) && PyFloat_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfVector1) + PyFloat_AsDouble(ElementOfVector2)));
        }
        else
        {
            PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
            return NULL;
        }

    }

    return NewVector;

}

static PyObject *method_VminusV(PyObject *self, PyObject *args)
{
    PyObject *ElementOfVector1, *ElementOfVector2;
    PyListObject *Vector1, *Vector2, *NewVector = PyList_New(0);
    Py_ssize_t n1, n2;
    int i;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Vector1, &PyList_Type, &Vector2))
    {
        return NULL;
    }

    n1 = PyList_Size(Vector1);
    n2 = PyList_Size(Vector2);

    if(n1 != n2)
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Vectros is different!");
        return NULL;
    }

    for(i=0; i<n1; i++)
    {

        ElementOfVector1 = PyList_GetItem(Vector1, i);
        ElementOfVector2 = PyList_GetItem(Vector2, i);

        if(PyLong_Check(ElementOfVector1) && PyLong_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfVector1) - PyLong_AsDouble(ElementOfVector2)));
        }
        else if(PyLong_Check(ElementOfVector1) && PyFloat_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfVector1) - PyFloat_AsDouble(ElementOfVector2)));
        }
        else if(PyFloat_Check(ElementOfVector1) && PyLong_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfVector1) - PyLong_AsDouble(ElementOfVector2)));
        }
        else if(PyFloat_Check(ElementOfVector1) && PyFloat_Check(ElementOfVector2))
        {
            PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfVector1) - PyFloat_AsDouble(ElementOfVector2)));
        }
        else
        {
            PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
            return NULL;
        }

    }

    return NewVector;

}

static PyObject *method_VdotV(PyObject *self, PyObject *args)
{
    PyObject *ElementOfVector1, *ElementOfVector2;
    PyListObject *Vector1, *Vector2;
    Py_ssize_t n1, n2;
    int i;
    double res = 0;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Vector1, &PyList_Type, &Vector2))
    {
        return NULL;
    }

    n1 = PyList_Size(Vector1);
    n2 = PyList_Size(Vector2);

    if(n1 != n2)
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Vectros is different!");
        return NULL;
    }

    for(i=0; i<n1; i++)
    {

        ElementOfVector1 = PyList_GetItem(Vector1, i);
        ElementOfVector2 = PyList_GetItem(Vector2, i);

        if(PyLong_Check(ElementOfVector1) && PyLong_Check(ElementOfVector2))
        {
            res = res + PyLong_AsDouble(ElementOfVector1) * PyLong_AsDouble(ElementOfVector2);
        }
        else if(PyLong_Check(ElementOfVector1) && PyFloat_Check(ElementOfVector2))
        {
            res = res + PyLong_AsDouble(ElementOfVector1) * PyFloat_AsDouble(ElementOfVector2);
        }
        else if(PyFloat_Check(ElementOfVector1) && PyLong_Check(ElementOfVector2))
        {
            res = res + PyFloat_AsDouble(ElementOfVector1) * PyLong_AsDouble(ElementOfVector2);
        }
        else if(PyFloat_Check(ElementOfVector1) && PyFloat_Check(ElementOfVector2))
        {
            res = res + PyFloat_AsDouble(ElementOfVector1) * PyFloat_AsDouble(ElementOfVector2);
        }
        else
        {
            PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
            return NULL;
        }

    }

    return PyFloat_FromDouble(res);

}

static PyObject *method_V3crossV3(PyObject *self, PyObject *args)
{
    PyObject *Pyx1, *Pyx2, *Pyx3, *Pyy1, *Pyy2, *Pyy3;
    PyListObject *Vector1, *Vector2, *NewVector = PyList_New(0);
    Py_ssize_t n1, n2;
    int i, j;
    double x1, x2, x3, y1, y2, y3;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Vector1, &PyList_Type, &Vector2))
    {
        return NULL;
    }

    n1 = PyList_Size(Vector1);
    n2 = PyList_Size(Vector2);

    if(n1 != n2 || n1 != 3)
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Vectros is different or != 3!");
        return NULL;
    }

    Pyx1 = PyList_GetItem(Vector1, 0);
    Pyx2 = PyList_GetItem(Vector1, 1);
    Pyx3 = PyList_GetItem(Vector1, 2);

    Pyy1 = PyList_GetItem(Vector2, 0);
    Pyy2 = PyList_GetItem(Vector2, 1);
    Pyy3 = PyList_GetItem(Vector2, 2);

    if(PyLong_Check(Pyx1))
    {
        x1 = PyLong_AsDouble(Pyx1);
    }
    else if(PyFloat_Check(Pyx1))
    {
        x1 = PyFloat_AsDouble(Pyx1);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
        return NULL;
    }

    if(PyLong_Check(Pyx2))
    {
        x2 = PyLong_AsDouble(Pyx2);
    }
    else if(PyFloat_Check(Pyx2))
    {
        x2 = PyFloat_AsDouble(Pyx2);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
        return NULL;
    }

    if(PyLong_Check(Pyx3))
    {
        x3 = PyLong_AsDouble(Pyx3);
    }
    else if(PyFloat_Check(Pyx3))
    {
        x3 = PyFloat_AsDouble(Pyx3);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
        return NULL;
    }

    if(PyLong_Check(Pyy1))
    {
        y1 = PyLong_AsDouble(Pyy1);
    }
    else if(PyFloat_Check(Pyy1))
    {
        y1 = PyFloat_AsDouble(Pyy1);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
        return NULL;
    }

    if(PyLong_Check(Pyy2))
    {
        y2 = PyLong_AsDouble(Pyy2);
    }
    else if(PyFloat_Check(Pyy2))
    {
        y2 = PyFloat_AsDouble(Pyy2);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
        return NULL;
    }

    if(PyLong_Check(Pyy3))
    {
        y3 = PyLong_AsDouble(Pyy3);
    }
    else if(PyFloat_Check(Pyy3))
    {
        y3 = PyFloat_AsDouble(Pyy3);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
        return NULL;
    }

    PyList_Append(NewVector, PyFloat_FromDouble(x2*y3 - x3*y2));
    PyList_Append(NewVector, PyFloat_FromDouble(x3*y1 - x1*y3));
    PyList_Append(NewVector, PyFloat_FromDouble(x1*y2 - x2*y1));

    return NewVector;

}

static PyObject *method_MatrixE(PyObject *self, PyObject *args)
{
    PyListObject *NewVector, *NewMatrix = PyList_New(0);
    int n, i, j;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "i", &n))
    {
        return NULL;
    }

    for(i=0; i<n; i++)
    {
        NewVector = PyList_New(0);

        for(j=0; j<n; j++)
        {
            if(i == j)
            {
                PyList_Append(NewVector, Py_BuildValue("i", 1));
            }
            else
            {
                PyList_Append(NewVector, Py_BuildValue("i", 0));
            }
        }

        PyList_Append(NewMatrix, NewVector);
    }

    return NewMatrix;
}

static PyObject *method_MxR(PyObject *self, PyObject *args)
{
    PyListObject *NewVector, *NewMatrix = PyList_New(0), *Matrix, *Vector, *ElementOfMatrix;
    int n, m, i, j;
    double R;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!d", &PyList_Type, &Matrix, &R))
    {
        return NULL;
    }

    n = PyList_Size(Matrix);
    m = PyList_Size(PyList_GetItem(Matrix, 0));

    for(i=0; i<n; i++)
    {
        NewVector = PyList_New(0);

        Vector = PyList_GetItem(Matrix, i);

        for(j=0; j<m; j++)
        {

            ElementOfMatrix = PyList_GetItem(Vector, j);

            if(PyLong_Check(ElementOfMatrix))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfMatrix)*R));
            }
            else if(PyFloat_Check(ElementOfMatrix))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfMatrix)*R));
            }
            else
            {
                PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
                return NULL;
            }
        }

        PyList_Append(NewMatrix, NewVector);
    }

    return NewMatrix;
}

static PyObject *method_MplusM(PyObject *self, PyObject *args)
{
    PyListObject *NewVector, *NewMatrix = PyList_New(0), *Matrix1, *Vector1, *ElementOfMatrix1, *Matrix2, *Vector2, *ElementOfMatrix2;
    int n, m, i, j;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Matrix1, &PyList_Type, &Matrix2))
    {
        return NULL;
    }

    n = PyList_Size(Matrix1);
    m = PyList_Size(PyList_GetItem(Matrix1, 0));

    if(n != PyList_Size(Matrix2) || m != PyList_Size(PyList_GetItem(Matrix2, 0)))
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Matrices is different!");
        return NULL;
    }

    for(i=0; i<n; i++)
    {
        NewVector = PyList_New(0);

        Vector1 = PyList_GetItem(Matrix1, i);
        Vector2 = PyList_GetItem(Matrix2, i);

        for(j=0; j<m; j++)
        {

            ElementOfMatrix1 = PyList_GetItem(Vector1, j);
            ElementOfMatrix2 = PyList_GetItem(Vector2, j);

            if(PyLong_Check(ElementOfMatrix1) && PyLong_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfMatrix1)+PyLong_AsDouble(ElementOfMatrix2)));
            }
            else if(PyLong_Check(ElementOfMatrix1) && PyFloat_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfMatrix1)+PyFloat_AsDouble(ElementOfMatrix2)));
            }
            else if(PyFloat_Check(ElementOfMatrix1) && PyLong_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfMatrix1)+PyLong_AsDouble(ElementOfMatrix2)));
            }
            else if(PyFloat_Check(ElementOfMatrix1) && PyFloat_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfMatrix1)+PyFloat_AsDouble(ElementOfMatrix2)));
            }
            else
            {
                PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
                return NULL;
            }
        }

        PyList_Append(NewMatrix, NewVector);
    }

    return NewMatrix;
}

static PyObject *method_MminusM(PyObject *self, PyObject *args)
{
    PyListObject *NewVector, *NewMatrix = PyList_New(0), *Matrix1, *Vector1, *ElementOfMatrix1, *Matrix2, *Vector2, *ElementOfMatrix2;
    int n, m, i, j;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Matrix1, &PyList_Type, &Matrix2))
    {
        return NULL;
    }

    n = PyList_Size(Matrix1);
    m = PyList_Size(PyList_GetItem(Matrix1, 0));

    if(n != PyList_Size(Matrix2) || m != PyList_Size(PyList_GetItem(Matrix2, 0)))
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Matrices is different!");
        return NULL;
    }

    for(i=0; i<n; i++)
    {
        NewVector = PyList_New(0);

        Vector1 = PyList_GetItem(Matrix1, i);
        Vector2 = PyList_GetItem(Matrix2, i);

        for(j=0; j<m; j++)
        {

            ElementOfMatrix1 = PyList_GetItem(Vector1, j);
            ElementOfMatrix2 = PyList_GetItem(Vector2, j);

            if(PyLong_Check(ElementOfMatrix1) && PyLong_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfMatrix1)-PyLong_AsDouble(ElementOfMatrix2)));
            }
            else if(PyLong_Check(ElementOfMatrix1) && PyFloat_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyLong_AsDouble(ElementOfMatrix1)-PyFloat_AsDouble(ElementOfMatrix2)));
            }
            else if(PyFloat_Check(ElementOfMatrix1) && PyLong_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfMatrix1)-PyLong_AsDouble(ElementOfMatrix2)));
            }
            else if(PyFloat_Check(ElementOfMatrix1) && PyFloat_Check(ElementOfMatrix2))
            {
                PyList_Append(NewVector, PyFloat_FromDouble(PyFloat_AsDouble(ElementOfMatrix1)-PyFloat_AsDouble(ElementOfMatrix2)));
            }
            else
            {
                PyErr_SetString(PyExc_TypeError, "list items must be Float or Long.");
                return NULL;
            }
        }

        PyList_Append(NewMatrix, NewVector);
    }

    return NewMatrix;
}

static PyObject *method_MxV(PyObject *self, PyObject *args)
{
    PyListObject *NewVector = PyList_New(0), *Matrix, *VectorInput, *VectorOfMatrix; //*ElementOfMatrix, *ElementOfVectorInput;
    PyTupleObject *NewArgs;
    int n, m, i, j;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Matrix, &PyList_Type, &VectorInput))
    {
        return NULL;
    }

    n = PyList_Size(Matrix);
    m = PyList_Size(VectorInput);

    if(PyList_Size(PyList_GetItem(Matrix, 0)) != m)
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Matrix and Vector is different!");
        return NULL;
    }

    for(i=0; i<n; i++)
    {
        NewArgs = PyTuple_New(2);

        VectorOfMatrix = PyList_GetItem(Matrix, i);

        PyTuple_SetItem(NewArgs, 0, VectorOfMatrix);
        PyTuple_SetItem(NewArgs, 1, VectorInput);

        PyList_Append(NewVector, method_VdotV(NULL, NewArgs));
    }

    return NewVector;
}

static PyObject *method_MxM(PyObject *self, PyObject *args)
{
    PyListObject *NewVector, *NewMatrix = PyList_New(0), *Matrix1, *Matrix2, *VectorColumn, *Vector1; //*ElementOfMatrix, *ElementOfVectorInput;
    PyTupleObject *NewArgs;
    int n, m, i, i1, j;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &Matrix1, &PyList_Type, &Matrix2))
    {
        return NULL;
    }

    n = PyList_Size(Matrix1);
    m = PyList_Size(PyList_GetItem(Matrix1, 0));

    if(m != PyList_Size(Matrix2) || n != PyList_Size(PyList_GetItem(Matrix2, 0)))
    {
        PyErr_Format(PyExc_AttributeError, "The sizes of Matrices are different!");
        return NULL;
    }

    for(i=0; i<n; i++)
    {
        NewVector = PyList_New(0);

        Vector1 = PyList_GetItem(Matrix1, i);

        for(j=0; j<m; j++)
        {
            VectorColumn = PyList_New(0);
            NewArgs = PyTuple_New(2);

            for(i1=0; i1<n; i1++)
            {
                PyList_Append(VectorColumn, PyList_GetItem(PyList_GetItem(Matrix2, i1), j));
            }

            PyTuple_SetItem(NewArgs, 0, Vector1);
            PyTuple_SetItem(NewArgs, 1, VectorColumn);

            PyList_Append(NewVector, method_VdotV(NULL, NewArgs));
        }

        PyList_Append(NewMatrix, NewVector);

    }

    return NewMatrix;
}

static PyMethodDef VectorAndMatrixMathMethods[] =
{
    {"Len", method_Len, METH_VARARGS, "Gives the len of the Vector"},
    {"Normalize", method_Normalize, METH_VARARGS, "Gives the normalized Vector of the Vector"},
    {"VxR", method_VxR, METH_VARARGS, "Gives the Vector powered on R"},
    {"VplusV", method_VplusV, METH_VARARGS, "Gives the Vector1 plus Vector2"},
    {"VminusV", method_VminusV, METH_VARARGS, "Gives the Vector1 minus Vector2"},
    {"VdotV", method_VdotV, METH_VARARGS, "Gives the Vector1 * Vector2 by theirs coordinats"},
    {"V3crossV3", method_V3crossV3, METH_VARARGS, "Gives the Vector1 X Vector2 (Vector1 and Vector2 must be of size 3)"},
    {"MatrixE", method_MatrixE, METH_VARARGS, "Gives the matrix with 1 on main diagonal and 0 on other positions"},
    {"MxR", method_MxR, METH_VARARGS, "Gives the matrix powered on R"},
    {"MplusM", method_MplusM, METH_VARARGS, "Gives the Matrix 1 plus Matrix 2"},
    {"MminusM", method_MminusM, METH_VARARGS, "Gives the Matrix 1 minus Matrix 2"},
    {"MxV", method_MxV, METH_VARARGS, "Gives the Matrix powered on Vector"},
    {"MxM", method_MxM, METH_VARARGS, "Gives the Matrix 1 powered on Matrix 2"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef VectorAndMatrixMathCModule =
{
    PyModuleDef_HEAD_INIT,
    "VectorAndMatrixMathC",
    "Python interface for the Vector and Matrix math C library function",
    -1,
    VectorAndMatrixMathMethods
};

PyMODINIT_FUNC PyInit_VectorAndMatrixMathC(void)
{
    return PyModule_Create(&VectorAndMatrixMathCModule);
}


