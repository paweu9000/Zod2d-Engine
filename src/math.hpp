#pragma once

#include <cmath>
#include <ostream>

namespace Math {
    template <typename T>
    struct Vec2 {
    public:
        T x, y;

        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}

        Vec2 unit() const {
            T len = length();
            return Vec2(x / len, y / len);
        }

        Vec2 operator+(const Vec2& other) const {
            return Vec2(x + other.x, y + other.y);
        }

        Vec2 operator-(const Vec2& other) const {
            return Vec2(x - other.x, y - other.y);
        }

        Vec2 operator*(const Vec2& other) const {
            return Vec2(x * other.x, y * other.y);
        }

        Vec2 operator/(const Vec2& other) const {
            return Vec2(x / other.x, y / other.y);
        }

        Vec2 operator*(T scalar) const {
            return Vec2(x * scalar, y * scalar);
        }

        Vec2 operator/(T scalar) const {
            return Vec2(x / scalar, y / scalar);
        }

        Vec2& operator+=(const Vec2& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vec2& operator-=(const Vec2& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vec2& operator*=(const Vec2& other) {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        Vec2& operator/=(const Vec2& other) {
            x /= other.x;
            y /= other.y;
            return *this;
        }

        bool operator==(const Vec2& other) const {
            return x == other.x && y == other.y;
        }

        bool operator!=(const Vec2& other) const {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
            os << "(" << vec.x << ", " << vec.y << ")";
            return os;
        }

        Vec2 normalize() const {
            T len = length();
            return Vec2(x / len, y / len);
        }

        T length() const {
            return std::sqrt(x * x + y * y);
        }

        T angle(const Vec2& other) const {
            T dotProduct = dot(other);
            T lengths = length() * other.length();
            return std::acos(dotProduct / lengths);
        }

        void setZero() {
            x = 0;
            y = 0;
        }

        Vec2 perpendicular() const {
            return Vec2(-y, x);
        }

        T distance(const Vec2& other) const {
            return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
        }

        Vec2 rotate(T angle) const {
            T rad = angle * (M_PI / 180.0f);
            T cosA = std::cos(rad);
            T sinA = std::sin(rad);
            return Vec2(x * cosA - y * sinA, x * sinA + y * cosA);
        }

        T dot(const Vec2& other) const {
            return x * other.x + y * other.y;
        }
        
        Vec2 interpolate(const Vec2& other, T t) const {
            return Vec2(x + t * (other.x - x), y + t * (other.y - y));
        }

        Vec2 project(const Vec2& other) const {
            T dotProduct = dot(other);
            T otherLengthSquared = other.x * other.x + other.y * other.y;
            return Vec2((dotProduct / otherLengthSquared) * other.x, (dotProduct / otherLengthSquared) * other.y);
        }

        Vec2 reject(const Vec2& other) const {
            return *this - project(other);
        }

        Vec2 reflect(const Vec2& normal) const {
            return *this - normal * 2.0 * dot(normal);
        }

        Vec2 scale(float factor) const {
            return Vec2(x * factor, y * factor);
        }

        Vec2 negate() const {
            return Vec2(-x, -y);
        }

        Vec2 hadamard(const Vec2& other) const {
            return *this * other;
        }

        T cross(const Vec2& other) const {
            return x * other.y - y * other.x;
        }

        T angleDegrees(const Vec2& other) const {
            return angle(other) * (180.0 / M_PI);
        }

        bool isZero() const {
            return x == 0 && y == 0;
        }

        bool isUnit() const {
            return std::fabs(length() - 1.0f);
        }

        Vec2 clamp(T minVal, T maxVal) const {
            return Vec2(
                std::fmax(minVal, std::fmin(x, maxVal)),
                std::fmax(minVal, std::fmin(y, maxVal))
            );
        }

        Vec2 min(const Vec2& other) const {
            return Vec2(
                std::fmin(x, other.x),
                std::fmin(y, other.y)
            );
        }

        Vec2 max(const Vec2& other) const {
            return Vec2(
                std::fmax(x, other.x),
                std::fmax(y, other.y)
            );
        }
    };
}