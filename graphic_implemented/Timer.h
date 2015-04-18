// Katie Quinn
// interface for simple timer class
#ifndef TIMER_H
#define TIMER_H

class Timer{
   public:
        Timer();
        void start();
        void stop();
        void pause();
        void unpause();
        int get_ticks(); //get timers time
        bool is_started();
        bool is_paused();
  private:
        int startTicks; //clock time at start
        int pausedTicks; //ticks stored when timer is paused
        bool paused;
        bool started;
};

#endif

