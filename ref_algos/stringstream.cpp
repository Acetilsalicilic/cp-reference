#include <sstream>
using namespace std;
int main() {
    string a;
    // Allows to put stuff into oss,
    // built from a
    ostringstream oss(a);
    
    oss << 5;

    string ans1 = oss.str();
}
