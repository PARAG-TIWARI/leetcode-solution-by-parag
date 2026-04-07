#include <vector>
#include <string>

using namespace std;

class Robot {
private:
    int w, h, totalSteps;
    int pos = 0;
    bool moved = false;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        // The total number of steps to return to (0,0)
        totalSteps = 2 * (w - 1) + 2 * (h - 1);
    }
    
    void step(int num) {
        moved = true;
        // Modulo reduces simulation to a single lap
        pos = (pos + num) % totalSteps;
    }
    
    vector<int> getPos() {
        // Map the single 'pos' integer back to X, Y coordinates
        if (pos < w) 
            return {pos, 0};
        if (pos < w + h - 1) 
            return {w - 1, pos - (w - 1)};
        if (pos < 2 * w + h - 2) 
            return {w - 1 - (pos - (w + h - 2)), h - 1};
        
        return {0, h - 1 - (pos - (2 * w + h - 3))};
    }
    
    string getDir() {
        // Special case: If we moved and landed on 0, it means we did full laps
        // and are facing South at (0,0).
        if (!moved) return "East";
        if (pos == 0) return "South";
        
        if (pos >= 1 && pos <= w - 1) return "East";
        if (pos >= w && pos <= w + h - 2) return "North";
        if (pos >= w + h - 1 && pos <= 2 * w + h - 3) return "West";
        
        return "South";
    }
};