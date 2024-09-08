#include <iostream>
#include <vector>
#include <cmath>

class LinearRegression {
private:
    double slope;
    double intercept;

public:
    LinearRegression() : slope(0), intercept(0) {}

    void fit(const std::vector<double>& X, const std::vector<double>& y) {
        double sum_X = 0, sum_Y = 0, sum_XY = 0, sum_X2 = 0;
        int n = X.size();

        for (int i = 0; i < n; ++i) {
            sum_X += X[i];
            sum_Y += y[i];
            sum_XY += X[i] * y[i];
            sum_X2 += X[i] * X[i];
        }

        slope = (n * sum_XY - sum_X * sum_Y) / (n * sum_X2 - sum_X * sum_X);
        intercept = (sum_Y - slope * sum_X) / n;
    }

    double predict(double x) const {
        return slope * x + intercept;
    };

    void print_params() const {
        std::cout << "Slope: " << slope << "\n";
        std::cout << "Intercept: " << intercept << "\n";
    }
};

int main() {
    std::vector<double> X = {1, 2, 3, 4, 5};
    std::vector<double> y = {5, 4, 3, 2, 1};

    LinearRegression model;
    model.fit(X, y);

    std::cout << "Model parameters:\n";
    model.print_params();

    double new_X = 6;
    std::cout << "Prediction for X = " << new_X << ": "
        << model.predict(new_X) << "\n";

    return 0;
}

