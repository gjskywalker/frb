import librosa, os, testDataSegmentation, random, numpy as np
from keras.models import Sequential
from keras.layers import Dense, Dropout, Conv2D, MaxPooling2D, Flatten
from keras.layers.advanced_activations import LeakyReLU
from keras.regularizers import l2 as L2
from tensorflow.keras.optimizers import SGD
from tensorflow.keras.layers import BatchNormalization
import tensorflow as tf
inputShape = (128, 300, 1)
numClasses = 50
x = np.random.normal(inputShape)
print(x.shape)
# adding first convolutionial layer with 64 filters and 3 by 3 kernal size, using the rectifier linear unit as the activation
y = Conv2D(64, (3, 3), input_shape=inputShape, activation='relu', padding='valid')(x)
# adding a batch normalization and maxpooling layer 3 by 5 (Note: We are compressing the 2nd diemension more in order to get a more square shape)
y = BatchNormalization()(y)
y = MaxPooling2D(pool_size=(3, 5))(y)
print(y.shape)
# adding second convolutionial layer with 32 filters and 1 by 3 kernal size, using the rectifier linear unit as the activation
model.add(Conv2D(32, (1, 3), input_shape=(numOfRows, numOfColumns, 1), activation='relu', padding='valid'))
# adding the first convolutionial layer with 32 filters and 3 by 3 kernal size, using the rectifier linear unit as the activation
model.add(Conv2D(32, (3, 3), input_shape=(numOfRows, numOfColumns, 1), activation='relu', padding='valid'))
# adding batch normalization layer
model.add(BatchNormalization())
# adding forth convolutionial layer with 32 filters and 1 by 3 kernal size, using the rectifier linear unit as the activation
model.add(Conv2D(32, (1, 3), input_shape=(numOfRows, numOfColumns, 1), activation='relu', padding='valid'))
# adding batch normalization and max pooling layers
model.add(BatchNormalization())
model.add(MaxPooling2D(pool_size=(2, 3)))
# adding fift convolutionial layer with 64 filters and 3 by 3 kernal size, using the rectifier linear unit as the activation
model.add(Conv2D(32, (3, 3), input_shape=(numOfRows, numOfColumns, 1), activation='relu', padding='valid'))
# adding batch normalization and max pooling layers
model.add(BatchNormalization())
model.add(MaxPooling2D(pool_size=(2, 2)))
# flattening the output in order to apply the fully connected layer
model.add(Flatten())
# adding a drop out for the regularizaing purposes
model.add(Dropout(0.2))
# adding a fully connected layer 128 filters
model.add(Dense(128, activation='relu'))
# adding a drop out for the regularizaing purposes
model.add(Dropout(0.2))
# adding softmax layer for the classification
model.add(Dense(numClasses, activation='softmax'))
# Compiling the model to generate a model
model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
