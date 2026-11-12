#include <cassert>
#include <cmath>
#include <iostream>

constexpr double DISCOUNT_THRESHOLD = 1000.0;
constexpr double DISCOUNT_RATE = 0.10;

double applyDiscount(double subtotal) {
    if (subtotal > DISCOUNT_THRESHOLD) {
        return subtotal * (1.0 - DISCOUNT_RATE);
    }
    return subtotal;
}

double calculateOrderTotal(double unitPrice, int quantity) {
    const double subtotal = unitPrice * quantity;
    return applyDiscount(subtotal);
}

bool almostEqual(double a, double b, double epsilon = 1e-6) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    // Case 1: Above discount threshold (250 * 5 = 1250 -> 1125)
    assert(almostEqual(calculateOrderTotal(250.0, 5), 1125.0));

    // Case 2: Below discount threshold (100 * 2 = 200 -> 200)
    assert(almostEqual(calculateOrderTotal(100.0, 2), 200.0));

    // Case 3: Exact boundary at threshold (200 * 5 = 1000 -> no discount)
    assert(almostEqual(calculateOrderTotal(200.0, 5), 1000.0));

    // Case 4: Zero quantity edge case
    assert(almostEqual(calculateOrderTotal(150.0, 0), 0.0));

    std::cout << "All characterization tests passed successfully!\n";
    return 0;
}