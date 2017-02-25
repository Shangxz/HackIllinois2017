import numpy as np
import tensorflow as tf
import math
import requests
import json
import matplotlib.pyplot as plt

x_data = [0, 0, 0, 0, 0, 0, 0, 4, 15, 87, 181, 510, 235, 222, 80, 73, 82, 0, 0, 0, 0, 0, 0, 0, 0]
y_data = [0]
def make_data(n):

    response = requests.get('http://localhost:8080/api')
    data = response.json()
    #print(data)
    value = json.loads(data)
    #print value
    temp = []
    y = [0]

    for i in value["Items"]:
        print i['Value']
        y[0] = i['Value']
        np.append(temp, y)

    
    x = [0]


    return x, y

def fit_line(n=1, log_progress=False):
    with tf.Session() as session:
        x = tf.placeholder(tf.float32, [n], name='x')
        y = tf.placeholder(tf.float32, [n], name='y')
        m = tf.Variable([1.0], trainable=True) # training variable: slope
        b = tf.Variable([1.0], trainable=True) # training variable: intercept
        y = tf.add(tf.mul(m, x), b) # fit y_i = m * x_i + b

        # actual values (for training)
        y_act = tf.placeholder(tf.float32, [n], name='y_')

        # minimize sum of squared error between trained and actual.
        error = tf.sqrt((y - y_act) * (y - y_act))
        # train_step = tf.train.GradientDescentOptimizer(0.01).minimize(error)
        train_step = tf.train.AdamOptimizer(0.05).minimize(error)

        # generate input and output data with a little random noise.
        x_in, y_star = make_data(25)

        init = tf.global_variables_initializer()
        session.run(init)
        feed_dict = {x: x_in, y_act: y_star}
        for i in range(30 * 25):
            y_i, m_i, b_i, _ = session.run([y, m, b, train_step], feed_dict)
            err = np.linalg.norm(y_i - y_star, 2)
            if log_progress:
                print("%3d | %.4f %.4f %.4e" % (i, m_i, b_i, err))

        print("Done! m = %f, b = %f, err = %e, iterations = %d"
              % (m_i, b_i, err, i))
        print("      x: %s" % x_in)
        print("Trained: %s" % y_i)
        print(" Actual: %s" % y_star)

        plt.plot(x_data, y_data, 'ro', label='Original Data')
        plt.legend()
        plt.show()

