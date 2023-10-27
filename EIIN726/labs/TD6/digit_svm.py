import pandas as pd

from sklearn import datasets, model_selection, svm

X_digit, y_digit = datasets.load_digits(return_X_y=True)

print(f"Number of samples: {len(X_digit)}")
print(f"Number of features: {len(X_digit[0])}")

X_digit_train, X_digit_test, y_digit_train, y_digit_test = model_selection.train_test_split(X_digit, y_digit, test_size=0.2)

# SVM with linear kernel
clf = svm.SVC(kernel='linear')
clf.fit(X_digit_train, y_digit_train)

print(f"Score: {clf.score(X_digit_test, y_digit_test)}")

# Evaluating SVM hyperparameters

df = []

for kernel in ['linear', 'poly', 'rbf', 'sigmoid']:
    for C in [0.1, 1, 10, 100]:
        for decision in ['ovo', 'ovr']:
            clf = svm.SVC(kernel=kernel, C=C, decision_function_shape=decision)
            clf.fit(X_digit_train, y_digit_train)
            score = clf.score(X_digit_test, y_digit_test)
            df.append([kernel, C, decision, score])

df = pd.DataFrame(df, columns=['kernel', 'C', 'decision_function_shape', 'score'])

# Order by score
df.sort_values(by=['score'], ascending=False, inplace=True)
print(df)

# Comparing OVO and OVR

X_digit_train, X_digit_test, y_digit_train, y_digit_test = model_selection.train_test_split(X_digit, y_digit, test_size=0.2, random_state=0)

clf = svm.SVC(kernel='linear', decision_function_shape='ovo')
clf.fit(X_digit_train, y_digit_train)