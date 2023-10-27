import pickle
from pathlib import Path

import pandas as pd

from sklearn import datasets, model_selection, svm
from tqdm import tqdm

print("MNIST")

if Path("cache/X_mnist.pkl").is_file() and Path("cache/y_mnist.pkl").is_file():
    with open("cache/X_mnist.pkl", "rb") as f:
        X_mnist = pickle.load(f)
    with open("cache/y_mnist.pkl", "rb") as f:
        y_mnist = pickle.load(f)
else:
    X_mnist, y_mnist = datasets.fetch_openml('mnist_784', version=1, return_X_y=True)

    # pickle the data
    Path("cache/X_mnist.pkl").write_bytes(pickle.dumps(X_mnist))
    Path("cache/y_mnist.pkl").write_bytes(pickle.dumps(y_mnist))

# Reduce the dataset
X_mnist = X_mnist[:1000]
y_mnist = y_mnist[:1000]

print(f"Number of samples: {len(X_mnist)}")
print(f"Number of features: {len(X_mnist.shape)}")

X_mnist_train, X_mnist_test, y_mnist_train, y_mnist_test = model_selection.train_test_split(X_mnist, y_mnist, test_size=0.2)

# SVM with linear kernel
clf = svm.SVC(kernel='linear')
clf.fit(X_mnist_train, y_mnist_train)

print(f"Score: {clf.score(X_mnist_test, y_mnist_test)}")

# Evaluating SVM hyperparameters

df = []

for kernel in tqdm(['linear', 'poly', 'rbf', 'sigmoid']):
    for C in [0.1, 1, 10, 100]:
        for decision in ['ovo', 'ovr']:
            clf = svm.SVC(kernel=kernel, C=C, decision_function_shape=decision)
            clf.fit(X_mnist_train, y_mnist_train)
            score = clf.score(X_mnist_test, y_mnist_test)
            df.append([kernel, C, decision, score])

df = pd.DataFrame(df, columns=['kernel', 'C', 'decision_function_shape', 'score'])

# Order by score
df.sort_values(by=['score'], ascending=False, inplace=True)
print(df)

# Comparing OVO and OVR

X_mnist_train, X_mnist_test, y_mnist_train, y_mnist_test = model_selection.train_test_split(X_mnist, y_mnist, test_size=0.2, random_state=0)

clf = svm.SVC(kernel='linear', decision_function_shape='ovo')
clf.fit(X_mnist_train, y_mnist_train)