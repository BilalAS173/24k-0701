#include<iostream>
#include <vector>
#include <string>
using namespace std;

enum class LogSeverity {
    INFO,
    WARNING,
    ERROR
};
class Logger {
private:
    std::vector<std::string> logs;
    const size_t MAX_LOGS = 1000;
    void storeLog(const std::string& message) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin());
        }
        logs.push_back(message);
    }
public:
    void logInfo(const std::string& message) {
        storeLog("[INFO] " + message);
    }

    void logWarning(const std::string& message) {
        storeLog("[WARN] " + message);
    }

    void logError(const std::string& message) {
        storeLog("[ERROR] " + message);
    }

    void log(const std::string& message, LogSeverity severity) {
        switch (severity) {
            case LogSeverity::INFO: logInfo(message); break;
            case LogSeverity::WARNING: logWarning(message); break;
            case LogSeverity::ERROR: logError(message); break;
        }
    }
    const std::vector<std::string>& getLogs(bool isAuthenticated) const {
        static std::vector<std::string> empty;
        return isAuthenticated ? logs : empty;
    }
};

int main() {
    Logger logger;
    logger.logInfo("Network module initialized successfully");
    logger.logWarning("Database connection slower than usual");
    logger.logError("File system error");
    logger.log("Cache cleared", LogSeverity::INFO);
    for (int i = 0; i < 1003; i++) {
        logger.logInfo("Log entry " + std::to_string(i));
    }
    cout << "Unauthenticated access:\n";
    for (const auto& log : logger.getLogs(false)) {
        cout << log << "\n";
    }
   cout << "\nAuthenticated access:\n";
    for (const auto& log : logger.getLogs(true)) {
        cout << log << "\n";
    }
    return 0;
}