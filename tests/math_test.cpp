#include <gtest/gtest.h>
#include <sstream>
#include <iomanip>
#include "../src/math.hpp"

namespace Math {
    template <typename T>
    void TestDefaultConstructor() {
        Vec2<T> vec;
        EXPECT_EQ(vec.x, 0);
        EXPECT_EQ(vec.y, 0);
    }

    template <typename T>
    void TestParameterizedConstructor() {
        Vec2<T> vec(static_cast<T>(3), static_cast<T>(4));
        EXPECT_EQ(vec.x, static_cast<T>(3));
        EXPECT_EQ(vec.y, static_cast<T>(4));
    }

    template <typename T>
    void TestNormalizeFunction() {
        Vec2<T> vec(static_cast<T>(3), static_cast<T>(4));
        Vec2<T> unitVec = vec.normalize();
        T length = std::sqrt(static_cast<T>(3) * static_cast<T>(3) + static_cast<T>(4) * static_cast<T>(4));
        EXPECT_NEAR(unitVec.x, static_cast<T>(3) / length, 1e-6);
        EXPECT_NEAR(unitVec.y, static_cast<T>(4) / length, 1e-6);
    }

    template <typename T>
    void TestAdditionOperator() {
        Vec2<T> vec1(static_cast<T>(1), static_cast<T>(2));
        Vec2<T> vec2(static_cast<T>(3), static_cast<T>(4));
        Vec2<T> result = vec1 + vec2;
        EXPECT_EQ(result.x, static_cast<T>(4));
        EXPECT_EQ(result.y, static_cast<T>(6));
    }

    template <typename T>
    void TestSubtractionOperator() {
        Vec2<T> vec1(static_cast<T>(5), static_cast<T>(7));
        Vec2<T> vec2(static_cast<T>(3), static_cast<T>(4));
        Vec2<T> result = vec1 - vec2;
        EXPECT_EQ(result.x, static_cast<T>(2));
        EXPECT_EQ(result.y, static_cast<T>(3));
    }

    template <typename T>
    void TestMultiplicationOperator() {
        Vec2<T> vec1(static_cast<T>(2), static_cast<T>(3));
        Vec2<T> vec2(static_cast<T>(4), static_cast<T>(5));
        Vec2<T> result = vec1 * vec2;
        EXPECT_EQ(result.x, static_cast<T>(8));
        EXPECT_EQ(result.y, static_cast<T>(15));
    }

    template <typename T>
    void TestDivisionOperator() {
        Vec2<T> vec1(static_cast<T>(8), static_cast<T>(15));
        Vec2<T> vec2(static_cast<T>(2), static_cast<T>(3));
        Vec2<T> result = vec1 / vec2;
        EXPECT_EQ(result.x, static_cast<T>(4));
        EXPECT_EQ(result.y, static_cast<T>(5));
    }

    template <typename T>
    void TestScalarMultiplicationOperator() {
        Vec2<T> vec(static_cast<T>(2), static_cast<T>(3));
        Vec2<T> result = vec * static_cast<T>(2);
        EXPECT_EQ(result.x, static_cast<T>(4));
        EXPECT_EQ(result.y, static_cast<T>(6));
    }

    template <typename T>
    void TestScalarDivisionOperator() {
        Vec2<T> vec(static_cast<T>(4), static_cast<T>(6));
        Vec2<T> result = vec / static_cast<T>(2);
        EXPECT_EQ(result.x, static_cast<T>(2));
        EXPECT_EQ(result.y, static_cast<T>(3));
    }

    template <typename T>
    void TestAdditionAssignmentOperator() {
        Vec2<T> vec1(static_cast<T>(1), static_cast<T>(2));
        Vec2<T> vec2(static_cast<T>(3), static_cast<T>(4));
        vec1 += vec2;
        EXPECT_EQ(vec1.x, static_cast<T>(4));
        EXPECT_EQ(vec1.y, static_cast<T>(6));
    }

    template <typename T>
    void TestEqualityOperator() {
        Vec2<T> vec1(static_cast<T>(1), static_cast<T>(2));
        Vec2<T> vec2(static_cast<T>(1), static_cast<T>(2));
        EXPECT_TRUE(vec1 == vec2);
    }

    template <typename T>
    void TestInequalityOperator() {
        Vec2<T> vec1(static_cast<T>(1), static_cast<T>(2));
        Vec2<T> vec2(static_cast<T>(3), static_cast<T>(4));
        EXPECT_TRUE(vec1 != vec2);
    }

    template <typename T>
    void TestLengthFunction() {
        Vec2<T> vec(static_cast<T>(3), static_cast<T>(4));
        EXPECT_EQ(vec.length(), std::sqrt(static_cast<T>(3) * static_cast<T>(3) + static_cast<T>(4) * static_cast<T>(4)));
    }

    template <typename T>
    void TestAngleFunction() {
        Vec2<T> vec1(static_cast<T>(1), static_cast<T>(0));
        Vec2<T> vec2(static_cast<T>(0), static_cast<T>(1));
        EXPECT_NEAR(vec1.angle(vec2), static_cast<T>(M_PI) / 2, 1e-6);
    }

    template <typename T>
    void TestSetZeroFunction() {
        Vec2<T> vec(static_cast<T>(3), static_cast<T>(4));
        vec.setZero();
        EXPECT_EQ(vec.x, static_cast<T>(0));
        EXPECT_EQ(vec.y, static_cast<T>(0));
    }

    template <typename T>
    void TestPerpendicularFunction() {
        Vec2<T> vec(static_cast<T>(1), static_cast<T>(0));
        Vec2<T> perpVec = vec.perpendicular();
        EXPECT_EQ(perpVec.x, static_cast<T>(0));
        EXPECT_EQ(perpVec.y, static_cast<T>(1));
    }

    template <typename T>
    void TestDistanceFunction() {
        Vec2<T> vec1(static_cast<T>(1), static_cast<T>(0));
        Vec2<T> vec2(static_cast<T>(4), static_cast<T>(0));
        EXPECT_EQ(vec1.distance(vec2), static_cast<T>(3));
    }

    template <typename T>
    void TestStreamOperator() {
        Vec2<T> vec(static_cast<T>(3), static_cast<T>(4));
        std::ostringstream oss;
        oss << vec;

        std::ostringstream expected;
        expected << "(" << std::fixed << std::setprecision(0) << static_cast<T>(3) << ", " << static_cast<T>(4) << ")";

        EXPECT_EQ(oss.str(), expected.str());
    }

    TEST(Vec2Test, DefaultConstructor) {
        TestDefaultConstructor<float>();
        TestDefaultConstructor<double>();
        TestDefaultConstructor<int>();
    }

    TEST(Vec2Test, ParameterizedConstructor) {
        TestParameterizedConstructor<float>();
        TestParameterizedConstructor<double>();
        TestParameterizedConstructor<int>();
    }

    TEST(Vec2Test, NormalizeFunction) {
        TestNormalizeFunction<float>();
        TestNormalizeFunction<double>();
    }

    TEST(Vec2Test, AdditionOperator) {
        TestAdditionOperator<float>();
        TestAdditionOperator<double>();
        TestAdditionOperator<int>();
    }

    TEST(Vec2Test, SubtractionOperator) {
        TestSubtractionOperator<float>();
        TestSubtractionOperator<double>();
        TestSubtractionOperator<int>();
    }

    TEST(Vec2Test, MultiplicationOperator) {
        TestMultiplicationOperator<float>();
        TestMultiplicationOperator<double>();
        TestMultiplicationOperator<int>();
    }

    TEST(Vec2Test, DivisionOperator) {
        TestDivisionOperator<float>();
        TestDivisionOperator<double>();
        TestDivisionOperator<int>();
    }

    TEST(Vec2Test, ScalarMultiplicationOperator) {
        TestScalarMultiplicationOperator<float>();
        TestScalarMultiplicationOperator<double>();
        TestScalarMultiplicationOperator<int>();
    }

    TEST(Vec2Test, ScalarDivisionOperator) {
        TestScalarDivisionOperator<float>();
        TestScalarDivisionOperator<double>();
        TestScalarDivisionOperator<int>();
    }

    TEST(Vec2Test, AdditionAssignmentOperator) {
        TestAdditionAssignmentOperator<float>();
        TestAdditionAssignmentOperator<double>();
        TestAdditionAssignmentOperator<int>();
    }

    TEST(Vec2Test, EqualityOperator) {
        TestEqualityOperator<float>();
        TestEqualityOperator<double>();
        TestEqualityOperator<int>();
    }

    TEST(Vec2Test, InequalityOperator) {
        TestInequalityOperator<float>();
        TestInequalityOperator<double>();
        TestInequalityOperator<int>();
    }

    TEST(Vec2Test, LengthFunction) {
        TestLengthFunction<float>();
        TestLengthFunction<double>();
        TestLengthFunction<int>();
    }

    TEST(Vec2Test, AngleFunction) {
        TestAngleFunction<float>();
        TestAngleFunction<double>();
    }

    TEST(Vec2Test, SetZeroFunction) {
        TestSetZeroFunction<float>();
        TestSetZeroFunction<double>();
        TestSetZeroFunction<int>();
    }

    TEST(Vec2Test, PerpendicularFunction) {
        TestPerpendicularFunction<float>();
        TestPerpendicularFunction<double>();
        TestPerpendicularFunction<int>();
    }

    TEST(Vec2Test, DistanceFunction) {
        TestDistanceFunction<float>();
        TestDistanceFunction<double>();
        TestDistanceFunction<int>();
    }

    TEST(Vec2Test, StreamOperator) {
        TestStreamOperator<float>();
        TestStreamOperator<double>();
        TestStreamOperator<int>();
    }

    template <typename T>
    void TestDefaultConstructorVec3() {
        Vec3<T> vec;
        EXPECT_EQ(vec.x, 0);
        EXPECT_EQ(vec.y, 0);
    }

    TEST(Vec3Test, DefaultConstructor) {
        TestDefaultConstructorVec3<float>();
        TestDefaultConstructorVec3<double>();
        TestDefaultConstructorVec3<int>();
    }
}