# NEWS System

A C++ application for monitoring physiological parameters in an ICU setting using the National Early Warning Score (NEWS) system. The application calculates risk scores based on patient vital signs and provides real-time updates via console dashboard and LED indicators.

## Features

- **NEWS Score Calculation**: Automatic calculation of National Early Warning Scores from 7 physiological parameters
- **Patient Management**: Track patients across 6 ICU beds with score history
- **Real-time Updates**: Observer pattern implementation for dashboard and LED notifications
- **Risk Assessment**: Four risk levels (Low, Low-Medium, Medium, High) with color-coded indicators
- **Comprehensive Testing**: 23 unit tests covering core functionality

## Quick Start

### Automated Build and Test
```bash
./build_and_test.sh
```

This script will:
- Check for required dependencies
- Build the main application
- Build and run all unit tests
- Provide colored output with status updates

### Manual Build

#### Build Main Application
```bash
make
# or
g++ -std=c++11 -Wall -o NEWS_System main.cpp ICU.cpp NEWSCalculator.cpp
```

#### Build with Tests
```bash
mkdir build
cd build
cmake ..
make
./run_tests
```

## Architecture

The system follows the Observer design pattern with the following components:

- **Data Structures**: `Parameters` (physiological data) and `Score` (results)
- **Core Classes**: `Patient` (data management), `NEWSCalculator` (scoring logic)
- **UI Components**: `Observer` interface, `Dashboard` (console output), `Led` (risk indicator)
- **Main Controller**: `ICU` (bed management and workflow)

## Installation

### Prerequisites
- C++11 compatible compiler (g++ recommended)
- CMake (for building tests)
- Google Test (gtest) for unit testing

### Dependencies
```bash
# Ubuntu/Debian
sudo apt install libgtest-dev cmake g++
```

### Build System
- **Main Application**: Makefile or direct g++ compilation
- **Tests**: CMake with Google Test framework
- **Automated Script**: `build_and_test.sh` for complete setup

## Usage

### Running the Application
```bash
./NEWS_System
```

### Menu Options
- **n**: Calculate new NEWS score for a patient
- **h**: View patient history
- **a**: List all patients
- **x**: Exit

### NEWS Parameters
The system evaluates 7 physiological parameters:
1. Respiration rate (breaths/min)
2. Oxygen saturation (%)
3. Supplemental oxygen use
4. Temperature (°C)
5. Systolic blood pressure (mmHg)
6. Heart rate (bpm)
7. Level of consciousness (AVPU)

### Risk Levels
- **Low** (0-4): Green
- **Low-Medium** (3 in any parameter): Yellow
- **Medium** (5-6): Orange
- **High** (7+): Red

## Testing

### Unit Tests
The project includes comprehensive unit tests using Google Test:

- **23 total tests** across 6 test suites
- **Coverage**: Core classes, parameter validation, scoring logic
- **Test Suites**:
  - PatientTest: Data management and history
  - ParametersTest: Input validation
  - NEWSCalculatorTest: Scoring algorithm
  - LedTest: Risk priority and colors
  - DashboardTest: UI updates
  - ICUTest: Basic instantiation

### Running Tests
```bash
cd build
./run_tests
```

All tests pass, validating core functionality including edge cases and boundary conditions.

### Test Coverage
- ~80% of core logic tested
- Parameter validation and scoring algorithms fully covered
- Observer pattern implementation verified
- Limitations: Interactive console methods require integration testing

## API Documentation

### Key Classes

#### Parameters Struct
```cpp
struct Parameters {
    int respRate, oxygenSat, systolicBP, heartRate;
    double temperature;
    bool supplementalOxygen;
    char consciousness; // A/V/P/U

    bool isValid() const; // Range validation
};
```

#### Score Struct
```cpp
struct Score {
    int value;              // 0-20
    std::string riskLevel;  // "Low", "Low-Medium", "Medium", "High"
    std::string timestamp;
};
```

#### Patient Class
```cpp
class Patient {
public:
    Patient(int id, std::string first, std::string last);
    void addScore(Score s);
    int getId() const;
    std::string getFullName() const;
    const std::vector<Score>& getHistory() const;
};
```

#### NEWSCalculator Class
```cpp
class NEWSCalculator {
public:
    static Score calculate(const Parameters& p);
};
```

#### Observer Pattern
```cpp
class Observer {
public:
    virtual void update(int bedNum, std::string name,
                       std::string risk, std::string time) = 0;
};

class Dashboard : public Observer { /* Console output */ };
class Led : public Observer { /* Color-coded risk indicator */ };
```

#### ICU Class
```cpp
class ICU {
private:
    Patient* beds[7]; // Beds 1-6
    std::vector<Observer*> observers;

public:
    void processNewScore();
    void printPatientHistory();
    void printAllPatients();
    void addObserver(Observer* obs);
};
```

## Scoring Algorithm

Each parameter contributes 0-3 points:
- **Respiration**: 9-11 (0), 12-20/21-24 (1/2), others (3)
- **Oxygen Sat**: 96+ (0), 94-95 (1), 92-93 (2), <92 (3)
- **Supplemental O2**: +2 if used
- **Temperature**: 36.1-38.0 (0), 35.1-36.0/38.1-39.0 (1), others (2)
- **BP**: 111-219 (0), 101-110 (1), 91-100 (2), <91 (3)
- **Heart Rate**: 51-90 (0), 41-50/91-110 (1), 111-130 (2), others (3)
- **Consciousness**: Alert (0), others (3)

Total score determines risk level with special case for Low-Medium.

## File Structure

```
├── main.cpp              # Application entry point
├── ICU.hpp/cpp           # Main controller
├── Patient.hpp           # Patient data class
├── Parameters.hpp        # Data structures
├── NEWSCalculator.hpp/cpp # Scoring logic
├── Observer.hpp          # Observer interface
├── Dashboard.hpp         # Console UI
├── Led.hpp               # LED indicator
├── test_*.cpp            # Unit tests (6 files)
├── CMakeLists.txt        # Build configuration
├── Makefile              # Alternative build
├── .gitignore            # Git ignore rules
├── TestCoverage.md       # Detailed test documentation
└── CodeDocumentation.md  # Detailed API docs
```

## Docker
```sh
docker compose -f 'docker-compose.yml' up -d --build 
docker start news_system_app
docker exec -it news_system_app /app/NEWS_System
```

## Contributing

### Code Style
- Use C++11 features
- Follow consistent naming conventions
- Include unit tests for new functionality
- Document public APIs

### Testing Recommendations
- Add mocking for console I/O testing
- Implement integration tests for full workflows
- Consider performance testing for large datasets
- Use code coverage tools (gcov) for metrics

## Future Enhancements

- Database persistence for patient data
- Network connectivity for remote monitoring
- Graphical user interface
- Historical trend analysis and charts
- Multi-threaded real-time monitoring
- Alert system for critical changes
- Export functionality for reports

## License

This project is developed for educational and demonstration purposes.

## Contact

For questions or contributions, please refer to the detailed documentation in `CodeDocumentation.md` and `TestCoverage.md`.

