#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <ios>

namespace vg 
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
        static std::ofstream m_out;
        static LogLevel m_log_level;

    public:
        static void SetPath(const std::string& path) {
            m_out.open(path, std::ios::app);
        }

        static void SetLevel(LogLevel logLevel) {
            m_log_level = logLevel;
        }
        static void Write(LogType type, const std::string& str) {
            SYSTEMTIME st;
            GetLocalTime(&st);
            std::string in_file;
           
            switch (type)
            {
            case LogType::Info:
                in_file += "[Info] " + str;
                break;

            case LogType::Error:
                in_file += "[Error] " + str;
                break;

            case LogType::Debug:
                in_file += "[Debug]" + str;
                break;

            default:
                break;
            }

            if (m_log_level == LogLevel::DEBUG) {
                std::cerr << "[" << st.wHour << "h" << ":" << st.wMinute << "m" << ":" << st.wSecond << "s" << "]" << in_file<<"\n";
            }
            m_out <<"[" << st.wYear << "." << st.wMonth << "." << st.wDay << "]" << "[" << st.wHour << "h" << ":" << st.wMinute << "m" << ":" << st.wSecond << "s" << "]" << in_file << "\n";

            m_out.flush();
        }


    };
}