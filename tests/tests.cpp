#include <gtest/gtest.h>
#include "../src/figure.h"
#include "../src/rhombus.h"
#include "../src/fugl.h"
#include "../src/sugl.h"
#include "../src/arr.h"

// Тесты для Point

TEST(PointTest, Initialization) {
    Point p{1.5, 2.5};
    EXPECT_DOUBLE_EQ(p.x, 1.5);
    EXPECT_DOUBLE_EQ(p.y, 2.5);
}

// Тесты для Rhombus
TEST(RhombusTest, ConstructorAndArea) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    Rhombus rhombus(p1, p2, p3, p4);
    
    EXPECT_DOUBLE_EQ(rhombus.area(), 2.0);
}

TEST(RhombusTest, GeometricCenter) {
    Point p1{0, 0}, p2{2, 2}, p3{4, 0}, p4{2, -2};
    Rhombus rhombus(p1, p2, p3, p4);
    Point center = rhombus.geometricCenter();
    
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(RhombusTest, CopyConstructor) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    Rhombus rhombus1(p1, p2, p3, p4);
    Rhombus rhombus2(rhombus1);
    
    EXPECT_TRUE(rhombus1 == rhombus2);
}

TEST(RhombusTest, AssignmentOperator) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    Rhombus rhombus1(p1, p2, p3, p4);
    Rhombus rhombus2;
    rhombus2 = rhombus1;
    
    EXPECT_TRUE(rhombus1 == rhombus2);
}

// Тесты для FUGL (Pentagon)
TEST(FUGLTest, ConstructorAndArea) {
    Point p1{0, 0}, p2{1, 2}, p3{3, 2}, p4{4, 0}, p5{2, -1};
    FUGL pentagon(p1, p2, p3, p4, p5);
    
    EXPECT_GT(pentagon.area(), 0.0);
}

TEST(FUGLTest, GeometricCenter) {
    Point p1{0, 0}, p2{2, 0}, p3{3, 2}, p4{1, 3}, p5{-1, 2};
    FUGL pentagon(p1, p2, p3, p4, p5);
    Point center = pentagon.geometricCenter();
    
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.4);
}

// Тесты для SUGL (Hexagon)
TEST(SUGLTest, ConstructorAndArea) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 1}, p4{3, 0}, p5{2, -1}, p6{1, -1};
    SUGL hexagon(p1, p2, p3, p4, p5, p6);
    
    EXPECT_GT(hexagon.area(), 0.0);
}

TEST(SUGLTest, GeometricCenter) {
    Point p1{0, 0}, p2{2, 0}, p3{3, 1}, p4{2, 2}, p5{0, 2}, p6{-1, 1};
    SUGL hexagon(p1, p2, p3, p4, p5, p6);
    Point center = hexagon.geometricCenter();
    
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

// Тесты для FigureArray
TEST(FigureArrayTest, AddAndSize) {
    FigureArray array;
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    
    Rhombus* rhombus = new Rhombus(p1, p2, p3, p4);
    array.addFigure(rhombus);
    
    EXPECT_EQ(array.size(), 1);
    EXPECT_FALSE(array.empty());
}

TEST(FigureArrayTest, TotalArea) {
    FigureArray array;
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    
    Rhombus* rhombus = new Rhombus(p1, p2, p3, p4);
    array.addFigure(rhombus);
    
    EXPECT_DOUBLE_EQ(array.totalArea(), 2.0);
}

TEST(FigureArrayTest, RemoveFigure) {
    FigureArray array;
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    
    Rhombus* rhombus = new Rhombus(p1, p2, p3, p4);
    array.addFigure(rhombus);
    
    EXPECT_EQ(array.size(), 1);
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 0);
    EXPECT_TRUE(array.empty());
}

TEST(FigureArrayTest, Clear) {
    FigureArray array;
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    
    Rhombus* rhombus = new Rhombus(p1, p2, p3, p4);
    array.addFigure(rhombus);
    
    EXPECT_EQ(array.size(), 1);
    array.clear();
    EXPECT_EQ(array.size(), 0);
    EXPECT_TRUE(array.empty());
}

TEST(FigureArrayTest, CopyConstructor) {
    FigureArray array1;
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    
    Rhombus* rhombus = new Rhombus(p1, p2, p3, p4);
    array1.addFigure(rhombus);
    
    FigureArray array2(array1);
    EXPECT_EQ(array1.size(), array2.size());
    EXPECT_DOUBLE_EQ(array1.totalArea(), array2.totalArea());
}

TEST(FigureArrayTest, AssignmentOperator) {
    FigureArray array1;
    Point p1{0, 0}, p2{1, 1}, p3{2, 0}, p4{1, -1};
    
    Rhombus* rhombus = new Rhombus(p1, p2, p3, p4);
    array1.addFigure(rhombus);
    
    FigureArray array2;
    array2 = array1;
    
    EXPECT_EQ(array1.size(), array2.size());
    EXPECT_DOUBLE_EQ(array1.totalArea(), array2.totalArea());
}

// Тесты на исключения
TEST(FigureArrayTest, OutOfRangeAccess) {
    FigureArray array;
    EXPECT_THROW(array[0], std::out_of_range);
}

TEST(FigureArrayTest, OutOfRangeRemove) {
    FigureArray array;
    EXPECT_THROW(array.removeFigure(0), std::out_of_range);
}

// Тесты ввода/вывода
TEST(IOStreamTest, RhombusInputOutput) {
    Rhombus rhombus;
    std::istringstream input("0 0 1 1 2 0 1 -1");
    input >> rhombus;
    
    std::ostringstream output;
    output << rhombus;
    
    EXPECT_FALSE(output.str().empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}