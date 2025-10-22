#include <iostream>
#include "figure.h"
#include "rhombus.h"
#include "fugl.h"
#include "sugl.h"
#include "arr.h"

int main() {
    FigureArray figures;

    std::cout << "=== FIGURE MANAGEMENT SYSTEM ===\n";
    std::cout << "Enter figures:\n";
    std::cout << "r - rhombus (4 points: x1 y1 x2 y2 x3 y3 x4 y4)\n";
    std::cout << "f - pentagon (5 points: x1 y1 x2 y2 x3 y3 x4 y4 x5 y5)\n";
    std::cout << "s - hexagon (6 points: x1 y1 x2 y2 x3 y3 x4 y4 x5 y5 x6 y6)\n";
    std::cout << "q - quit input\n\n";

    char choice;
    while (std::cin >> choice) {
        if (choice == 'q') break;

        Figure* newFig = nullptr;
        try {
            switch (choice) {
                case 'r':
                    newFig = new Rhombus();
                    std::cout << "Enter 4 points for rhombus: ";
                    break;
                case 'f':
                    newFig = new FUGL();
                    std::cout << "Enter 5 points for pentagon: ";
                    break;
                case 's':
                    newFig = new SUGL();
                    std::cout << "Enter 6 points for hexagon: ";
                    break;
                default:
                    std::cout << "Unknown figure type. Try again.\n";
                    continue;
            }

            std::cin >> *newFig;
            figures.addFigure(newFig);
            std::cout << "Figure added. Total figures: " << figures.size() << "\n\n";
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
            delete newFig;
        }
    }

    std::cout << "\n=== FIGURES INFORMATION ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i << ":\n";
        std::cout << "  " << *figures[i] << "\n";
        
        Point center = figures[i]->geometricCenter();
        std::cout << "  Geometric center: (" << center.x << ", " << center.y << ")\n";
        
        double area = figures[i]->area();
        std::cout << "  Area: " << area << "\n\n";
    }

    std::cout << "Total area of all figures: " << figures.totalArea() << "\n";
    std::cout << "Array capacity: " << figures.getCapacity() << "\n";

    if (figures.size() > 0) {
        std::cout << "\nEnter index to delete (0-" << figures.size() - 1 << "): ";
        size_t index;
        if (std::cin >> index) {
            try {
                figures.removeFigure(index);
                std::cout << "Figure at index " << index << " deleted.\n";
                std::cout << "Remaining figures: " << figures.size() << "\n";
                std::cout << "Updated total area: " << figures.totalArea() << "\n";
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }

    FigureArray figuresCopy = figures;
    std::cout << "\nCopied array size: " << figuresCopy.size() << "\n";

    return 0;
}