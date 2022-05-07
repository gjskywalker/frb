import numpy as np
from numpy import genfromtxt
import matplotlib.pyplot as plt
import keras

x_train = genfromtxt(r'D:\Denoiser-master\compressed_dataset\train_data.csv', delimiter=',')
y_train = genfromtxt(r'D:\Denoiser-master\compressed_dataset\train_labels.csv', delimiter=',')
x_test = genfromtxt(r'D:\Denoiser-master\compressed_dataset\test_data.csv', delimiter=',')
y_test = genfromtxt(r'D:\Denoiser-master\compressed_dataset\test_labels.csv', delimiter=',')
print('\nShape train CSV:', x_train.shape)


class LossHistory(keras.callbacks.Callback):
    def on_train_begin(self, logs={}):
        self.losses = {'batch':[], 'epoch':[]}
        self.accuracy = {'batch':[], 'epoch':[]}
        self.val_loss = {'batch':[], 'epoch':[]}
        self.val_accuracy = {'batch':[], 'epoch':[]}

    def on_batch_end(self, batch, logs={}):
        self.losses['batch'].append(logs.get('loss'))
        self.accuracy['batch'].append(logs.get('accuracy'))
        self.val_loss['batch'].append(logs.get('val_loss'))
        self.val_accuracy['batch'].append(logs.get('val_accuracy'))

    def on_epoch_end(self, batch, logs={}):
        self.losses['epoch'].append(logs.get('loss'))
        self.accuracy['epoch'].append(logs.get('accuracy'))
        self.val_loss['epoch'].append(logs.get('val_loss'))
        self.val_accuracy['epoch'].append(logs.get('val_accuracy'))

    def loss_plot(self, loss_type):
        iters = range(len(self.losses[loss_type]))
        plt.figure()
        # acc
        #plt.subplot(121)
        plt.plot(iters, self.accuracy[loss_type], 'r', label='train acc')
        plt.plot(iters, self.val_accuracy[loss_type], 'b', label='val acc')
        plt.ylabel('accuracy')
        plt.grid(True)
        plt.legend(loc="lower right")
        plt.show()
        # loss
        #plt.subplot(122)
        plt.figure()
        plt.plot(iters, self.losses[loss_type], 'g', label='train loss')
        #if loss_type == 'epoch':
            # val_acc
        #plt.subplot(121)

            # val_loss
        #plt.subplot(122)
        plt.plot(iters, self.val_loss[loss_type], 'k', label='val loss')

#        plt.xlabel(loss_type)

        #plt.subplot(122)
        #plt.xlabel(loss_type)
        plt.ylabel('loss')
        plt.grid(True)
        plt.legend(loc="upper right")
        plt.show()


# converting to one hot
from keras.utils.np_utils import to_categorical

y_train = to_categorical(y_train, num_classes=10)
y_test = to_categorical(y_test, num_classes=10)

# reshaping to 2D
x_train = np.reshape(x_train, (x_train.shape[0], 40, 5))
x_test = np.reshape(x_test, (x_test.shape[0], 40, 5))
print('\nShape train2D:', x_train.shape)

# reshaping to shape required by CNN
x_train = np.reshape(x_train, (x_train.shape[0], 40, 5, 1))
x_test = np.reshape(x_test, (x_test.shape[0], 40, 5, 1))
print('\nShape train_CNN:', x_train.shape)

from keras import Sequential
from keras.layers import Dense, Conv2D, MaxPooling2D, Flatten, Dropout

# forming model
model = Sequential()

# adding layers and forming the model
model.add(Conv2D(64, kernel_size=5, strides=1, padding="Same", activation="relu", input_shape=(40, 5, 1)))
model.add(MaxPooling2D(padding="same"))
model.add(Conv2D(128, kernel_size=5, strides=1, padding="same", activation="relu"))
model.add(MaxPooling2D(padding="same"))
model.add(Dropout(0.3))
model.add(Flatten())
model.add(Dense(256, activation="relu"))
model.add(Dropout(0.3))
model.add(Dense(512, activation="relu"))
model.add(Dropout(0.3))
model.add(Dense(10, activation="softmax"))

# compiling
model.compile(optimizer="adam", loss="categorical_crossentropy", metrics=["accuracy"])
history = LossHistory()
# training the model
model.fit(x_train, y_train, batch_size=50, epochs=40,verbose=1,validation_data=(x_test, y_test),callbacks=[history])
from keras.models import load_model

model.save('model.h5')
print('\n\n Model Saved. \n\n')

score = model.evaluate(x_test, y_test,verbose=0)
print('Test score:', score[0])
print('Test accuracy:', score[1])

history.loss_plot('epoch')
#print(train_loss_score)
#print(test_loss_score)

