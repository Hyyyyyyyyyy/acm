import tensorflow as tf
from time import time
import tensorflow.examples.tutorials.mnist.input_data as input_data  # 导入下载数据集手写体
mnist = input_data.read_data_sets("C:\\Users\\doudo\\Code\\ML\\MNIST\\MNIST_data", one_hot=True)

class SEQ2SEQNet:  # 创建一个SEQ2SEQNet类
    def __init__(self):
        self.x = tf.placeholder(dtype=tf.float32, shape=[None, 28, 28], name='input_x')  # 创建数据占位符
        self.y = tf.placeholder(dtype=tf.float32, shape=[None, 10], name='input_y')  # 创建标签占位符

        self.fc1_w = tf.Variable(tf.truncated_normal(shape=[128, 10], dtype=tf.float32, stddev=tf.sqrt(1 / 10)))  # 定义 输出层/全链接层 w
        self.fc1_b = tf.Variable(tf.zeros(shape=[10], dtype=tf.float32))  # 定义 输出层/全链接层 偏值b

    # 前向计算
    def forward(self):
        # 编码
        with tf.variable_scope('encode'):  # 创建一个变量空间 encode
            self.encoder_cell = tf.nn.rnn_cell.BasicLSTMCell(128)  # 创建128个LSTM的RNN结构(细胞结构)
            self.encoder_states = self.encoder_cell.zero_state(100, dtype=tf.float32)  # 初始化细胞的状态为 0, 传入初始化批次 和数据类型
            self.encoder_output, self.encoder_state = tf.nn.dynamic_rnn(self.encoder_cell, self.x, initial_state=self.encoder_states, time_major=False)  # 将细胞cell 和数据 self.x 初始化状态传入RNN细胞结构 获得两个返回值 output 和 状态state
            self.flat = tf.transpose(self.encoder_output, [1, 0, 2])[-1]  # 取rnn_output的输出状态的 每个输出的最后一行 (相当于 self.rnn_ouput[:, -1, :])
            self.flat1 = tf.expand_dims(self.flat, axis=1)  # 增加了一个维度
            self.flat2 = tf.tile(self.flat1, [1, 4, 1])  # 将增加的那个维度进行 复制为 4行 不复制也行 reshape为 NSV结构[批次, 步长, 数据]也行.

        # 解码
        with tf.variable_scope('decode'):  # 创建一个变量空间 decode
            self.decoder_cell = tf.nn.rnn_cell.BasicLSTMCell(128)  # 创建128个LSTM的RNN结构
            self.decoder_states = self.decoder_cell.zero_state(100, dtype=tf.float32)  # 初始化细胞的状态为 0, 传入初始化批次 和数据类型
            self.decoder_output, self.decoder_state = tf.nn.dynamic_rnn(self.decoder_cell, self.flat2, initial_state=self.decoder_states, time_major=False)  # 将细胞cell 和数据 self.flat2 初始化状态传入RNN细胞结构 获得两个返回值 output 和 状态state
            self.flat3 = tf.transpose(self.decoder_output, [1, 0, 2])[-1]  # 同上
            self.fc_y = tf.nn.relu(tf.matmul(self.flat3, self.fc1_w)+self.fc1_b)  # 全链接层
            self.output = tf.nn.softmax(self.fc_y)  # softmax分类

    # 后向计算
    def backward(self):
        self.cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=self.y, logits=self.fc_y))  # 定义损失, softmax交叉熵
        self.opt = tf.train.AdamOptimizer().minimize(self.cost)  # 使用AdamOptimizer优化损失

    # 计算测试集识别精度
    def acc(self):
        # 将预测值 output 和 标签值 self.y 进行比较
        self.acc1 = tf.equal(tf.argmax(self.output, 1), tf.argmax(self.y, 1))
        #  最后对比较出来的bool值 转换为float32类型后 求均值就可以看到满值为 1的精度显示
        self.accaracy = tf.reduce_mean(tf.cast(self.acc1, dtype=tf.float32))

net = SEQ2SEQNet()  # 启动tensorflow绘图的SEQ2SEQNet
net.forward()  # 启动前向计算
net.backward()  # 启动后向计算
net.acc()  # 启动精度计算
init = tf.global_variables_initializer()  # 定义初始化tensorflow所有变量操作

t1 = time()
with tf.Session() as sess:  # 创建一个Session会话
        sess.run(init)  # 执行init变量内的初始化所有变量的操作
        summ = 0.0
        cnt = 0
        for i in range(1000):  # 训练1000次
            ax, ay = mnist.train.next_batch(100)  # 从mnist数据集中取数据出来 ax接收图片 ay接收标签
            ax_batch = ax.reshape(-1, 28, 28)  # 将取出的 图片数据 reshape成 NSV 结构
            loss, output, accaracy, _ = sess.run(fetches=[net.cost, net.output, net.accaracy, net.opt], feed_dict={net.x: ax_batch, net.y: ay})  # 将数据喂进编码网络
            # print(loss)  # 打印损失
            # print(accaracy)  # 打印训练精度
            if i % 10 == 0:  # 每训练10次
                cnt += 1
                test_ax, test_ay = mnist.test.next_batch(100)  # 则使用测试集对当前网络进行测试
                test_ax_batch = test_ax.reshape(-1, 28, 28)  # 将取出的 图片数据 reshape成 NSV 结构
                test_output = sess.run(fetches=net.output, feed_dict={net.x: test_ax_batch})  # 将数据喂进编码网络  接收一个output值
                test_acc = sess.run(tf.equal(tf.argmax(test_output, 1), tf.argmax(test_ay, 1)))  # 对output值和标签y值进行求比较运算
                test_accaracy = sess.run(tf.reduce_mean(tf.cast(test_acc, dtype=tf.float32)))  # 求出精度的准确率进行打印
                if cnt > 90:
                    summ += test_accaracy
                print(test_accaracy)  # 打印当前测试集的精度
        print("accaracy: %.2f%%" % float(summ/10.0*100.0))  # 打印当前测试集的精度
print(time()-t1)