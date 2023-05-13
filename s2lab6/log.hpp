#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>

namespace wk 
{

    enum class LogLevel {
        DEBUG,
        RELEASE
    };
    enum class LogType {
        Info,
        Error,
        Debug
    };

    class Log {
    private:
        static std::ofstream w_out;
        static LogLevel w_log_level;

    public:
        static void SetPath(const std::string& path) {
            w_out.open(path);
        }

        static void SetLevel(LogLevel logLevel) {
            w_log_level = logLevel;
        }
        static void Write(LogType type, const std::string& str) {
            SYSTEMTIME st;
            GetLocalTime(&st);
            std::string in_file;
            switch (type)
            {
            case LogType::Info:
                in_file += "Info: " + str;
                break;

            case LogType::Error:
                in_file += "Error: " + str;
                break;

            case LogType::Debug:
                in_file += "Debug" + str;
                break;

            default:
                break;
            }

            if (w_log_level == LogLevel::DEBUG) {
                std::cerr << in_file << "\n" << st.wHour << "h" << ":" << st.wMinute << "m" << ":" << st.wSecond << "s" << "\n";
            }
            w_out << in_file << "\n" << st.wHour << "h" << ":" << st.wMinute << "m" << ":" << st.wSecond << "s" << "\n";
            w_out.flush();
        }


    };

}