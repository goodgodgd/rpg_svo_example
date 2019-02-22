#ifndef TUMFILELOGGER_H
#define TUMFILELOGGER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
<<<<<<< HEAD
#define VO_BENCH_NO_GUI_AND_ENABLE_LOGGING
=======
>>>>>>> 8fe4bc09c86b510a2adc34679910552bec06abba

class TicToc
{
  public:
    TicToc()
    {
        tic();
    }

    void tic()
    {
        start = std::chrono::steady_clock::now();
    }

    double toc()
    {
        end = std::chrono::steady_clock::now();
        double elapsed_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
        return elapsed_ms;
    }

  private:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
};


class TumFileLogger 
{
public:
    static TumFileLogger& instance() 
    { 
        static TumFileLogger* instance = new TumFileLogger(); 
        return *instance; 
    }

    void init(string filename_)
    {
        filename = filename_;
        frame_log.clear();
    }

    void push(vector<double> frameres)
    {
        frame_log.push_back(frameres);
    }

    void dump()
    {
        cout << "dump pose results on " << filename << endl;
        cout << "num frames = " << frame_log.size() << endl;
        ofstream fout(filename, ios::trunc);
        fout.setf(ios::fixed, ios::floatfield);
        fout.precision(6);
        for(auto frameres: frame_log)
        {
            for(double val: frameres)
                fout << val << " ";
            fout << endl;
        }
    }

private:
    TumFileLogger() {}
    vector<vector<double>> frame_log;
    string filename;
};

#endif
