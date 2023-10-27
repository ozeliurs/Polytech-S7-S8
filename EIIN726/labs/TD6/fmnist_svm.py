import pickle
from pathlib import Path

import pandas as pd

from sklearn import datasets, model_selection, svm
from tqdm import tqdm

print("Fashion-MNIST")


if Path("cache/X_fmnist.pkl").is_file() and Path("cache/y_fmnist.pkl").is_file():
    with open("cache/X_fmnist.pkl", "rb") as f:
        X_fmnist = pickle.load(f)
    with open("cache/y_fmnist.pkl", "rb") as f:
        y_fmnist = pickle.load(f)
else:
    X_fmnist, y_fmnist = datasets.fetch_openml('Fashion-MNIST', version=1, return_X_y=True)

    # pickle the data
    Path("cache/X_fmnist.pkl").write_bytes(pickle.dumps(X_fmnist))
    Path("cache/y_fmnist.pkl").write_bytes(pickle.dumps(y_fmnist))

# reduce number of data
X_fmnist = X_fmnist[:10000]
y_fmnist = y_fmnist[:10000]

print(f"Number of samples: {len(X_fmnist)}")
print(f"Number of features: {X_fmnist.shape[1]}")

X_fmnist_train, X_fmnist_test, y_fmnist_train, y_fmnist_test = model_selection.train_test_split(X_fmnist, y_fmnist, test_size=0.2)

# Evaluating SVM hyperparameters

df = []

kernels = ['linear', 'poly', 'rbf', 'sigmoid']
Cs = [0.1, 1, 10, 100]
decisions = ['ovo', 'ovr']

for kernel, C, decision in tqdm([(kernel, C, decision) for kernel in kernels for C in Cs for decision in decisions]):
    clf = svm.SVC(kernel=kernel, C=C, decision_function_shape=decision)
    clf.fit(X_fmnist_train, y_fmnist_train)
    score = clf.score(X_fmnist_test, y_fmnist_test)
    df.append([kernel, C, decision, score])

df = pd.DataFrame(df, columns=['kernel', 'C', 'decision_function_shape', 'score'])

# Order by score
df.sort_values(by=['score'], ascending=False, inplace=True)
print(df)

# Comparing OVO and OVR

X_fmnist_train, X_fmnist_test, y_fmnist_train, y_fmnist_test = model_selection.train_test_split(X_fmnist, y_fmnist, test_size=0.2, random_state=0)

clf = svm.SVC(kernel='linear', decision_function_shape='ovo')
clf.fit(X_fmnist_train, y_fmnist_train)