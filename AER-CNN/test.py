import numpy as np
import os
i = 0
path = "TestData/"
Class_names = os.listdir(path)
X_Test = np.load('X_test.npy')
Y_Test = np.load('Y_test.npy')
for Class_name in Class_names:
    temp = np.load(path+ '/' +Class_name)
    #X_Test[i] = temp
    Class_names[i] = Class_name[0:len(Class_name)-4]
    i += 1
np.save('Class_names.npy',Class_names)
a = np.load('TestData/Airplane.npy')
print(Y_Test.shape)