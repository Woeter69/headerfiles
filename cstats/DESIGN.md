# CStats Header File Design & Reusability Guide

## Design Philosophy

The `cstats.h` library follows a **header-only interface pattern** with clean separation of concerns, providing a comprehensive statistical analysis toolkit for C++ applications.

### Core Design Principles

#### 1. **Single-Purpose Header Guard**
```cpp
#ifndef CSTATS_H
#define CSTATS_H
```
Prevents multiple inclusion issues when used across different translation units.

#### 2. **Pure Function Declarations**
The header contains **only function prototypes** with no implementation details, enabling:
- Fast compilation (implementation separated in `cstats.cpp`)
- Easy API browsing and documentation
- Clean separation between interface and implementation
- Reduced compile-time dependencies

#### 3. **Comprehensive Documentation**
Each function includes Doxygen-style comments with:
- `@brief` - Clear description of functionality
- `@param` - Parameter specifications and constraints
- `@return` - Return value documentation
- `@note` - Important side effects (e.g., array sorting, memory requirements)

#### 4. **Logical Organization**
Functions are grouped into semantic categories with clear section markers:

| Category | Functions | Purpose |
|----------|-----------|---------|
| **Basic Statistics** | mean, median, mode, variance, stdev, min, max, sum, range | Fundamental descriptive statistics |
| **Advanced Statistics** | percentile, quartiles, IQR, skewness, kurtosis, z-scores | Distribution analysis |
| **Inferential Statistics** | standardError, confidenceInterval95 | Statistical inference |
| **Robust Statistics** | trimmedMean, weightedMean, MAD | Outlier-resistant measures |
| **Correlation Analysis** | covariance, correlation | Bivariate relationships |
| **Regression Analysis** | linearRegressionSlope, linearRegressionIntercept, rSquared | Predictive modeling |
| **Alternative Means** | geometricMean, harmonicMean, rootMeanSquare | Specialized averages |
| **Vector Operations** | dotProduct, crossProduct, vectorMagnitude, vectorAngle | Linear algebra |
| **Array Operations** | cumulativeSum, sortArray, copyArray | Data manipulation |
| **Helper Functions** | printSummaryStats | Convenience utilities |

## Architecture

### File Structure
```
cstats/
├── cstats.h          # Header file (interface declarations)
├── cstats.cpp        # Implementation file
├── test_all.cpp      # Comprehensive test suite
├── README.md         # User documentation
└── DESIGN.md         # This file (design documentation)
```

### Dependency Graph
```
User Code
    ↓
cstats.h (declarations only)
    ↓
cstats.cpp (implementations)
    ↓
<cmath> (standard library)
```

## How to Reuse This Library

### Method 1: Direct Integration (Recommended for Small Projects)

**Step 1:** Copy files to your project
```bash
cp cstats.h cstats.cpp /path/to/your/project/
```

**Step 2:** Include in your code
```cpp
#include "cstats.h"
```

**Step 3:** Compile together
```bash
g++ -o myapp main.cpp cstats.cpp -lm
```

**Advantages:**
- Simple and straightforward
- No installation required
- Easy to modify for project-specific needs
- Full control over the code

### Method 2: Static Library (Recommended for Large Projects)

**Step 1:** Create static library
```bash
g++ -c cstats.cpp -o cstats.o
ar rcs libcstats.a cstats.o
```

**Step 2:** Install system-wide (optional)
```bash
sudo cp cstats.h /usr/local/include/
sudo cp libcstats.a /usr/local/lib/
```

**Step 3:** Link in your project
```bash
g++ -o myapp main.cpp -lcstats -lm
```

**Advantages:**
- Faster compilation (library pre-compiled)
- Reusable across multiple projects
- Professional deployment approach

### Method 3: CMake Integration (Recommended for Modern C++ Projects)

**CMakeLists.txt:**
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Add cstats as a library
add_library(cstats cstats.cpp)
target_include_directories(cstats PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link math library
target_link_libraries(cstats PUBLIC m)

# Your executable
add_executable(myapp main.cpp)
target_link_libraries(myapp PRIVATE cstats)
```

**Build:**
```bash
mkdir build && cd build
cmake ..
make
```

**Advantages:**
- Cross-platform compatibility
- Automatic dependency management
- Integration with modern C++ toolchains
- Easy to extend and maintain

### Method 4: Header-Only Conversion (Advanced)

To make it truly header-only, move all implementations from `cstats.cpp` into `cstats.h` and mark functions as `inline`:

```cpp
// In cstats.h
inline double mean(const double data[], int n) {
    if (n <= 0) return 0.0;
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    return total / n;
}
```

**Advantages:**
- Single-file distribution
- No linking required
- Template-friendly

**Disadvantages:**
- Longer compilation times
- Larger binary size (if not optimized)
- Less clear separation of interface/implementation

## Key Design Strengths

### 1. Minimal Dependencies
- Only requires `<cmath>` for mathematical operations
- No external library dependencies (Boost, Eigen, etc.)
- Pure C++ with C-style arrays (maximum compatibility)
- Works with C++98 and later standards

### 2. Const-Correctness
Most functions use `const double data[]` to prevent accidental modification:
```cpp
double mean(const double data[], int n);        // ✓ Cannot modify
double median(double data[], int n);            // ✗ Sorts array (documented)
```

Functions that modify arrays are clearly documented in their `@brief` descriptions.

### 3. Error Handling Strategy
Returns sensible defaults for invalid inputs rather than throwing exceptions:
- Returns `0.0` for numeric functions with invalid input
- Returns `false` for boolean functions that fail
- Suitable for embedded systems and real-time applications
- No exception overhead

```cpp
double mean(const double data[], int n) {
    if (n <= 0) return 0.0;  // Safe default
    // ... computation
}
```

### 4. Array-Based Interface
Uses raw arrays instead of STL containers:
```cpp
double data[] = {1.0, 2.0, 3.0};
double result = mean(data, 3);
```

**Benefits:**
- Zero overhead abstraction
- Compatibility with C code
- Easy integration with legacy codebases
- Works with stack-allocated arrays
- No dynamic memory allocation

### 5. Comprehensive Test Suite
The `test_all.cpp` file demonstrates:
- Proper usage patterns for all 50+ functions
- Edge case handling
- Expected outputs
- Integration examples

### 6. Memory Safety
- No dynamic memory allocation (user controls memory)
- Pre-allocated output arrays for functions like `cumulativeSum()`
- Clear documentation of memory requirements
- No memory leaks possible

## Reusability Patterns

### Pattern 1: Data Analysis Pipeline
```cpp
#include "cstats.h"
#include <iostream>

int main() {
    double data[] = {85.5, 92.0, 78.5, 88.0, 95.5, 82.0, 90.0};
    int n = sizeof(data) / sizeof(data[0]);
    
    // Preserve original for multiple analyses
    double copy[n];
    copyArray(data, copy, n);
    
    // Run analyses
    double avg = mean(data, n);
    double med = median(copy, n);  // Sorts copy, not original
    double sd = stdev(data, n);
    
    std::cout << "Mean: " << avg << std::endl;
    std::cout << "Median: " << med << std::endl;
    std::cout << "Std Dev: " << sd << std::endl;
    
    // Comprehensive summary
    printSummaryStats(data, n);
    
    return 0;
}
```

### Pattern 2: Statistical Comparison
```cpp
#include "cstats.h"
#include <iostream>

int main() {
    double control[] = {10.2, 10.5, 9.8, 10.1, 10.3};
    double treatment[] = {11.5, 12.0, 11.8, 11.2, 11.9};
    int n1 = 5, n2 = 5;
    
    // Compare groups
    double mean1 = mean(control, n1);
    double mean2 = mean(treatment, n2);
    double se1 = standardError(control, n1);
    double se2 = standardError(treatment, n2);
    
    std::cout << "Control: " << mean1 << " ± " << se1 << std::endl;
    std::cout << "Treatment: " << mean2 << " ± " << se2 << std::endl;
    std::cout << "Difference: " << (mean2 - mean1) << std::endl;
    
    return 0;
}
```

### Pattern 3: Regression Analysis
```cpp
#include "cstats.h"
#include <iostream>

int main() {
    double study_hours[] = {2.0, 3.0, 4.0, 5.0, 6.0};
    double test_scores[] = {65.0, 72.0, 78.0, 85.0, 90.0};
    int n = 5;
    
    // Perform regression
    double slope = linearRegressionSlope(study_hours, test_scores, n);
    double intercept = linearRegressionIntercept(study_hours, test_scores, n);
    double r2 = rSquared(study_hours, test_scores, n);
    double r = correlation(study_hours, test_scores, n);
    
    std::cout << "Regression equation: score = " 
              << slope << " * hours + " << intercept << std::endl;
    std::cout << "Correlation: " << r << std::endl;
    std::cout << "R-squared: " << r2 << std::endl;
    
    return 0;
}
```

### Pattern 4: Vector Operations
```cpp
#include "cstats.h"
#include <iostream>

int main() {
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};
    int n = 3;
    
    // Vector calculations
    double dot = dotProduct(v1, v2, n);
    double mag1 = vectorMagnitude(v1, n);
    double mag2 = vectorMagnitude(v2, n);
    double angle = vectorAngle(v1, v2, n);
    
    std::cout << "Dot product: " << dot << std::endl;
    std::cout << "Magnitude v1: " << mag1 << std::endl;
    std::cout << "Angle (radians): " << angle << std::endl;
    
    // Vector operations
    double result[3];
    vectorAdd(v1, v2, result, n);
    std::cout << "v1 + v2 = [" << result[0] << ", " 
              << result[1] << ", " << result[2] << "]" << std::endl;
    
    return 0;
}
```

### Pattern 5: Robust Statistics with Outliers
```cpp
#include "cstats.h"
#include <iostream>

int main() {
    double data[] = {10.2, 10.5, 9.8, 10.1, 10.3, 50.0};  // 50.0 is outlier
    int n = 6;
    
    // Compare regular vs robust measures
    double regular_mean = mean(data, n);
    double trimmed = trimmedMean(data, n, 20.0);  // Trim 20% from each end
    
    double copy[n];
    copyArray(data, copy, n);
    double med = median(copy, n);
    
    std::cout << "Regular mean: " << regular_mean << " (affected by outlier)" << std::endl;
    std::cout << "Trimmed mean: " << trimmed << " (robust)" << std::endl;
    std::cout << "Median: " << med << " (robust)" << std::endl;
    
    return 0;
}
```

## Extensibility Guide

### Adding New Functions

**Step 1:** Add declaration in `cstats.h` under appropriate category
```cpp
// ============================================================================
// YOUR CATEGORY
// ============================================================================

/**
 * @brief Your function description
 * @param data Array of values
 * @param n Number of elements
 * @return Result description
 */
double yourFunction(const double data[], int n);
```

**Step 2:** Add implementation in `cstats.cpp`
```cpp
double yourFunction(const double data[], int n) {
    if (n <= 0) return 0.0;  // Error handling
    
    // Your implementation
    double result = 0.0;
    // ...
    
    return result;
}
```

**Step 3:** Add test case in `test_all.cpp`
```cpp
cout << "--- YOUR CATEGORY ---" << endl;
TEST_RESULT("yourFunction(test_data)", yourFunction(data, n));
```

**Step 4:** Update `README.md` documentation
```markdown
#### `double yourFunction(const double data[], int n)`
Description of what it does and when to use it.
```

### Maintaining Backward Compatibility

When extending the library:
- ✓ Add new functions freely
- ✓ Add optional parameters with defaults
- ✗ Don't change existing function signatures
- ✗ Don't change return types
- ✗ Don't change parameter order

## Best Practices for Users

### 1. Array Preservation
Some functions modify input arrays (sorting). Always copy if you need the original:
```cpp
double original[] = {5.0, 1.0, 3.0, 2.0, 4.0};
double copy[5];
copyArray(original, copy, 5);
double med = median(copy, 5);  // original unchanged
```

### 2. Memory Management
Pre-allocate output arrays for functions that return arrays:
```cpp
double data[] = {1.0, 2.0, 3.0, 4.0};
double cumsum[4];  // Pre-allocate
cumulativeSum(data, cumsum, 4);
```

### 3. Error Checking
Check return values for edge cases:
```cpp
double cv = coefficientOfVariation(data, n);
if (cv == 0.0) {
    // Could mean: n <= 0, mean is 0, or stdev is 0
    // Check your data
}
```

### 4. Data Validation
Validate data before calling specialized functions:
```cpp
// Geometric mean requires positive values
bool all_positive = true;
for (int i = 0; i < n; i++) {
    if (data[i] <= 0) {
        all_positive = false;
        break;
    }
}
if (all_positive) {
    double gm = geometricMean(data, n);
}
```

## Performance Considerations

### Time Complexity
| Function | Complexity | Notes |
|----------|-----------|-------|
| mean, sum, min, max | O(n) | Single pass |
| variance, stdev | O(n) | Two passes (mean + variance) |
| median, percentile | O(n²) | Bubble sort used |
| mode | O(n²) | Nested loops for frequency |
| correlation | O(n) | Single pass after means |

### Optimization Opportunities
For large datasets, consider:
1. Replace bubble sort with quicksort (O(n log n))
2. Use single-pass variance algorithm (numerically less stable)
3. Implement parallel processing for independent calculations
4. Use SIMD instructions for vector operations

### Memory Usage
- All functions use O(1) additional space
- No dynamic allocation
- Stack-friendly for embedded systems

## Common Pitfalls and Solutions

### Pitfall 1: Forgetting Array Modification
```cpp
// ❌ Wrong
double data[] = {5, 1, 3, 2, 4};
double med = median(data, 5);
double avg = mean(data, 5);  // data is now sorted!

// ✓ Correct
double data[] = {5, 1, 3, 2, 4};
double copy[5];
copyArray(data, copy, 5);
double med = median(copy, 5);
double avg = mean(data, 5);  // data unchanged
```

### Pitfall 2: Division by Zero
```cpp
// ❌ Wrong
double cv = coefficientOfVariation(all_zeros, n);  // Returns 0.0

// ✓ Correct
double m = mean(data, n);
if (m != 0.0) {
    double cv = coefficientOfVariation(data, n);
}
```

### Pitfall 3: Invalid Data for Specialized Functions
```cpp
// ❌ Wrong
double data[] = {-1, 2, 3};
double gm = geometricMean(data, 3);  // Returns 0.0 (negative value)

// ✓ Correct
// Validate data first or use appropriate mean type
double am = mean(data, 3);  // Arithmetic mean works with negatives
```

## Integration Examples

### With C Code
```c
// main.c
#include "cstats.h"
#include <stdio.h>

int main() {
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double avg = mean(data, 5);
    printf("Mean: %f\n", avg);
    return 0;
}
```

Compile: `gcc main.c cstats.cpp -lstdc++ -lm -o myapp`

### With C++ STL
```cpp
#include "cstats.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<double> vec = {1.0, 2.0, 3.0, 4.0, 5.0};
    double avg = mean(vec.data(), vec.size());
    std::cout << "Mean: " << avg << std::endl;
    return 0;
}
```

### With Python (via ctypes)
```python
import ctypes
import numpy as np

# Load library
lib = ctypes.CDLL('./libcstats.so')
lib.mean.argtypes = [ctypes.POINTER(ctypes.c_double), ctypes.c_int]
lib.mean.restype = ctypes.c_double

# Use function
data = np.array([1.0, 2.0, 3.0, 4.0, 5.0])
result = lib.mean(data.ctypes.data_as(ctypes.POINTER(ctypes.c_double)), len(data))
print(f"Mean: {result}")
```

## Version History & Roadmap

### Current Version: 1.0
- 50+ statistical functions
- Comprehensive test suite
- Full documentation

### Future Enhancements (Potential)
- [ ] Faster sorting algorithms (quicksort, mergesort)
- [ ] Matrix operations (matrix multiplication, determinant)
- [ ] Time series analysis (autocorrelation, moving averages)
- [ ] Hypothesis testing (t-test, chi-square)
- [ ] Distribution functions (normal, binomial, etc.)
- [ ] SIMD optimizations for vector operations
- [ ] OpenMP parallelization for large datasets

## License & Contributing

This library is provided as-is for educational and commercial use.

**Contributing Guidelines:**
1. Maintain const-correctness
2. Add comprehensive documentation
3. Include test cases
4. Follow existing naming conventions
5. Ensure backward compatibility
6. Update README.md and DESIGN.md

## Conclusion

The `cstats.h` library provides a robust, well-documented, and highly reusable statistical toolkit for C++ applications. Its clean design, minimal dependencies, and comprehensive functionality make it suitable for:

- Scientific computing
- Data analysis applications
- Embedded systems
- Educational projects
- Legacy code integration
- Real-time systems

The modular architecture ensures easy extension while maintaining backward compatibility and performance.
