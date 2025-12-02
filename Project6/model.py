import tensorflow as tf
import numpy as np

# Load MNIST
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()
x_train = x_train.reshape(-1, 784).astype("float32") / 255.0
x_test = x_test.reshape(-1, 784).astype("float32") / 255.0

# Model
model = tf.keras.Sequential([
    tf.keras.layers.Input(shape=(784,)),
    tf.keras.layers.Dense(128, activation="relu"),
    tf.keras.layers.Dense(10, activation="softmax")
])

model.compile(optimizer="adam",
              loss="sparse_categorical_crossentropy",
              metrics=["accuracy"])

# Train
model.fit(x_train, y_train, epochs=3, batch_size=32)

# Evaluate
model.evaluate(x_test, y_test)

# Export weights
W1, B1 = model.layers[0].get_weights()
W2, B2 = model.layers[1].get_weights()

def write_array(f, name, arr):
    f.write(f"float {name}[{arr.size}] = {{")
    f.write(",".join([f"{x:.6f}" for x in arr.flatten()]))
    f.write("};\n\n")

with open("weights.h", "w") as f:
    f.write("// Auto-generated weights\n\n")
    write_array(f, "W1", W1)
    write_array(f, "B1", B1)
    write_array(f, "W2", W2)
    write_array(f, "B2", B2)

print("Exported weights → weights.h")
