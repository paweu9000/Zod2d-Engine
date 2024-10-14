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

    template <typename T>
    struct Vec3 {
        public:
        T x, y, z;

        Vec3() : x(0), y(0), z(0) {}
        Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

        Vec3 unit() const {
            T len = length();
            return Vec3(x / len, y / len);
        }

        Vec3 operator+(const Vec3& other) const {
            return Vec3(x + other.x, y + other.y, z + other.z);
        }

        Vec3 operator-(const Vec3& other) const {
            return Vec3(x - other.x, y - other.y, z - other.z);
        }

        Vec3 operator*(const Vec3& other) const {
            return Vec3(x * other.x, y * other.y, z * other.z);
        }

        Vec3 operator/(const Vec3& other) const {
            return Vec3(x / other.x, y / other.y, z / other.z);
        }

        Vec3 operator*(T scalar) const {
            return Vec3(x * scalar, y * scalar, z * scalar);
        }

        Vec3 operator/(T scalar) const {
            return Vec3(x / scalar, y / scalar, z / scalar);
        }

        Vec3& operator+=(const Vec3& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        Vec3& operator-=(const Vec3& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        Vec3& operator*=(const Vec3& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }

        Vec3& operator/=(const Vec3& other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
        }

        bool operator==(const Vec3& other) const {
            return x == other.x && y == other.y && z == other.z;
        }

        bool operator!=(const Vec3& other) const {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
            os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
            return os;
        }

        Vec3 normalize() const {
            T len = length();
            return Vec3(x / len, y / len, z / len);
        }

        T length() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        T angle(const Vec3& other) const {
            T dotProduct = dot(other);
            T lengths = length() * other.length();
            return std::acos(dotProduct / lengths);
        }

        void setZero() {
            x = 0;
            y = 0;
            z = 0;
        }

        Vec3 perpendicular() const {
            return Vec3(-y, x, z);
        }

        T distance(const Vec3& other) const {
            return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z));
        }

        Vec3 rotate(T angle) const {
            T rad = angle * (M_PI / 180.0f);
            T cosA = std::cos(rad);
            T sinA = std::sin(rad);
            return Vec3(x * cosA - y * sinA, x * sinA + y * cosA, z);
        }

        T dot(const Vec3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }
        
        Vec3 interpolate(const Vec3& other, T t) const {
            return Vec3(x + t * (other.x - x), y + t * (other.y - y), z + t * (other.z - z));
        }

        Vec3 project(const Vec3& other) const {
            T dotProduct = dot(other);
            T otherLengthSquared = other.x * other.x + other.y * other.y + other.z * other.z;
            return Vec3((dotProduct / otherLengthSquared) * other.x, 
                (dotProduct / otherLengthSquared) * other.y,
                (dotProduct / otherLengthSquared) * other.z);
        }

        Vec3 reject(const Vec3& other) const {
            return *this - project(other);
        }

        Vec3 reflect(const Vec3& normal) const {
            return *this - normal * 2.0 * dot(normal);
        }

        Vec3 scale(float factor) const {
            return Vec3(x * factor, y * factor, z * factor);
        }

        Vec3 negate() const {
            return Vec3(-x, -y, -z);
        }

        Vec3 hadamard(const Vec3& other) const {
            return *this * other;
        }

        T angleDegrees(const Vec3& other) const {
            return angle(other) * (180.0 / M_PI);
        }

        bool isZero() const {
            return x == 0 && y == 0 && z == 0;
        }

        bool isUnit() const {
            return std::fabs(length() - 1.0f);
        }

        Vec3 clamp(T minVal, T maxVal) const {
            return Vec3(
                std::fmax(minVal, std::fmin(x, maxVal)),
                std::fmax(minVal, std::fmin(y, maxVal)),
                std::fmax(minVal, std::fmin(z, maxVal))
            );
        }

        Vec3 min(const Vec3& other) const {
            return Vec3(
                std::fmin(x, other.x),
                std::fmin(y, other.y),
                std::fmin(z, other.z)
            );
        }

        Vec3 max(const Vec3& other) const {
            return Vec3(
                std::fmax(x, other.x),
                std::fmax(y, other.y),
                std::fmax(z, other.z)
            );
        }
    };
}