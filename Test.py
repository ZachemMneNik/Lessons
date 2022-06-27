import VectorAndMatrixMathC as VMM
import random

TestVector0 = [0, 0, 0, 0, 0]
TestVector1 = [1, 2, 3]
TestVector2 = [1.1251, 2.2526, 7.15276]
TestVector3 = [15.1251, -32.8568, -157.067, 21, 15.1255]
TestVector4 = [15.1251, -32.8568, -157.067, 21, 15.1255, -57.3463]

##Matrix = []
##
##for i in range(3):
##    Vector = []
##    for j in range(3):
##        Vector.append(round(100 * random.random(),3))
##    Matrix.append(Vector)
##print(Matrix)

Matrix1 = [[21.113, 58.529], [75.636, 39.996]]
Matrix2 = [[48.299, 41.666], [31.189, 44.187]]
Matrix3 = [[86.252, 73.961, 50.202], [7.094, 99.495, 62.944]]
Matrix4 = [[79.038, 40.87, 62.812], [54.592, 68.364, 15.084], [82.503, 27.197, 24.009]]
Matrix5 = [[22.276, 29.5, 63.897], [33.601, 79.305, 40.296], [94.904, 64.829, 52.696]]

R = 7

print(VMM.__doc__)
print(VMM.__name__)

#Len
print('\nLen')
print(VMM.Len(TestVector0))
print(VMM.Len(TestVector1))
print(VMM.Len(TestVector2))
print(VMM.Len(TestVector3))
print(VMM.Len(TestVector4))

#Normalization
print('\nNormalization')
print(VMM.Normalize(TestVector0))
print(VMM.Normalize(TestVector1))
print(VMM.Normalize(TestVector2))
print(VMM.Normalize(TestVector3))
print(VMM.Normalize(TestVector4))

#Power on Digits
print('\nPower on Digit')
print(VMM.VxR(TestVector0, 2))
print(VMM.VxR(TestVector1, 2.15))
print(VMM.VxR(TestVector2, 2))
print(VMM.VxR(TestVector3, 15.67))
print(VMM.VxR(TestVector4, 0.08))

#VplusV
print('\n Vector plus Vector')
#print(VMM.VplusV(TestVector0, TestVector1))
print(VMM.VplusV(TestVector1, TestVector2))
print(VMM.VplusV(TestVector3, TestVector3))

#VminusV
print('\n Vector minus Vector')
#print(VMM.VminusV(TestVector0, TestVector1))
print(VMM.VminusV(TestVector1, TestVector2))
print(VMM.VminusV(TestVector3, TestVector3))

#VdotV
print('\n Vector dot Vector')
#print(VMM.VdotV(TestVector0, TestVector1))
print(VMM.VdotV(TestVector1, TestVector2))
print(VMM.VdotV(TestVector3, TestVector3))

#V3crossV3
print('\n Vector3 cros Vector3')
print(VMM.V3crossV3([1, 0, 0], [0, 1, 0]))
print(VMM.V3crossV3([1, 0, 0], [1, 0, 0]))
print(VMM.V3crossV3(TestVector1, TestVector2))
#print(VMM.V3crossV3(TestVector3, TestVector3))

#MatrixE
print('\n Matrix E of any sizes')
print(VMM.MatrixE(1))
print(VMM.MatrixE(2))
print(VMM.MatrixE(3))
print(VMM.MatrixE(4))

#MxR
print('\n Matrix powered on Digit')
print(VMM.MxR(Matrix1, R))
print(VMM.MxR(Matrix2, R))
print(VMM.MxR(Matrix3, R))
print(VMM.MxR(Matrix4, R))
print(VMM.MxR(Matrix5, R))

#MplusM
print('\n Matrix1 plus Matrix 2')
print(VMM.MplusM(Matrix1, Matrix2))
print(VMM.MplusM(Matrix3, Matrix3))
print(VMM.MplusM(Matrix4, Matrix5))

#MminusM
print('\n Matrix1 minus Matrix 2')
print(VMM.MminusM(Matrix1, Matrix2))
print(VMM.MminusM(Matrix3, Matrix3))
print(VMM.MminusM(Matrix4, Matrix5))

#MxV
print('\n Matrix x Vector')
print(VMM.MxV(Matrix3, TestVector2))
print(VMM.MxV(Matrix4, TestVector2))
print(VMM.MxV(Matrix3, TestVector1))

#MxM
print('\n Matrix 1 x Matrix 2')
print(VMM.MxM(Matrix1, Matrix2))
print(VMM.MxM(Matrix3, Matrix3))
print(VMM.MxM(Matrix4, Matrix5))
