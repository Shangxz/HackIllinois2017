import tensorflow as tf
import numpy as np
import requests
import json
sess = tf.InteractiveSession()  #define a session
# Create 100 phony x, y data points in NumPy, y = x * 0.1 + 0.3
response = requests.get('http://localhost:8080/api')
data = response.json()
#print(data)
value = json.loads(data)
#print value
temp = []
y_data = [0]

for i in value["Items"]:
    print i['Value']
    y_data[0] = i['Value']
    np.append(temp, y_data)

x_data = [0, 0, 0, 0, 0, 0, 0, 4, 15, 87, 181, 510, 235, 222, 80, 73, 82, 0, 0, 0, 0, 0, 0, 0, 0]
#x = [0]
# Try to find values for W and b that compute y_data = W * x_data + b
# (We know that W should be 0.1 and b 0.3, but Tensorflow will
# figure that out for us.)
W = tf.Variable(tf.random_uniform([1], -1.0, 1.0))
b = tf.Variable(tf.zeros([1]))
y = W * x_data + b

# Minimize the mean squared errors.
loss = tf.reduce_mean(tf.square(y - y_data))
optimizer = tf.train.GradientDescentOptimizer(0.5)
train = optimizer.minimize(loss)

# Before starting, initialize the variables.  We will 'run' this first.
init = tf.initialize_all_variables()

# Launch the graph.
sess = tf.Session()
sess.run(init)

#### ----> ADD THIS LINE <---- ####
writer = tf.train.SummaryWriter("/tmp/test", sess.graph)

# Fit the line.
for step in xrange(201):
    sess.run(train)
    if step % 20 == 0:
        print(step, sess.run(W), sess.run(b))

# Learns best fit is W: [0.1], b: [0.3]