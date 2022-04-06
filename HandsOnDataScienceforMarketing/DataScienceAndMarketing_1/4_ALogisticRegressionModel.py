import numpy as np
import matplotlib.pyplot as plt

from sklearn.linear_model import LogisticRegression

if __name__ == '__main__':
    input_data = np.array([
        [0, 0],
        [0.25, 0.25],
        [0.5, 0.5],
        [1, 1]
    ])

    output_data = [0, 0, 1, 1]

    # Create a logistic regression instance, which inherently contains the model.
    logit_model = LogisticRegression()

    # Train this model with the given data.
    logit_model.fit(input_data, output_data)

    print("Printing the coefficients of the model:")
    print(logit_model.coef_)

    print("Printing the intercept of the model:")
    print(logit_model.intercept_)

    # Predicting values based on the trained model
    print("Predicting the values of [[2,2], [-1, -1]:")
    print(logit_model.predict(np.array([[2, 2], [-1, -1]])))

    plt.scatter(input_data[:, 0], input_data[:, 1], color=[('red' if x == 1 else 'blue') for x in output_data])
    plt.xlabel('x data')
    plt.ylabel('y data')
    plt.grid()
    plt.show()