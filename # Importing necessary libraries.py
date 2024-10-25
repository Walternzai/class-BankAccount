# Importing necessary libraries
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import joblib

# Loading the dataset
data = pd.read_csv('road_accidents.csv')

# Preprocessing data - handling missing values
data = data.dropna()

# Feature selection
X = data[['speed', 'weather_condition', 'vehicle_age']]
y = data['accident_severity']

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Model training
model = LinearRegression()
model.fit(X_train, y_train)

# Model evaluation
y_pred = model.predict(X_test)
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print(f"Mean Squared Error: {mse}")
print(f"R-squared: {r2}")

# Displaying the coefficients
coefficients = pd.DataFrame(model.coef_, X.columns, columns=['Coefficient'])
print(coefficients)

# Save the model
joblib.dump(model, 'road_accident_severity_model.pkl')
print("Model saved as 'road_accident_severity_model.pkl'")

# Hypothetical prediction
hypothetical_data = np.array([[60, 1, 5]])
predicted_severity = model.predict(hypothetical_data)
print(f"Predicted Accident Severity: {predicted_severity[0]}")
