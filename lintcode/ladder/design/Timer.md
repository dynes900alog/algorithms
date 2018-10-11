# Timer Callback

## Description
~~~
Design 

Assume you have a system function:
void register_system_timer_callback(unsigned long absolute_time, std::function<void()> callback);

How to implement a soft timer that can register muliple timers/callbacks register and trigger them?


callback define example: 
typedef void (*callback)(void);
void register_callback(callback ptr_reg_callback) {
    // trigger callback
    (*ptr_reg_callback)();
}

void my_callback(void) {
    print("inside callback\n");
}

it main() {
    callback ptr_my_callback = my_callback;
    register_callback(ptr_my_callback);
}

~~~

**Example**
```

```
**Challenge**  

## Link
[Timer](http://massivetechinterview.blogspot.com/2015/06/timer-callback-techinterview.html)

## Method
1. callback + map 
Key point: 

## Solution
1.1 map + callback
~~~
map<unsigned long, std::function<void()>> record;

unsigned long current_timer = LONG_MAX;

// actual call back fucntion
void wrapper() {

    record[current_timer]();
    record.erase(current_timer);

    if (!record.empty()) {
        auto it = record.begin();
        current_timer = it->first;

        register_system_timer_callback(it->first, std::function<void()>(wrapper));
    }
}

// register your own callback with relative timer
void register_timer_callback(unsigned long relative_timer, std::function<void()> callback) {
    if (relative_timer == 0) {
        callback();
    }

    auto cur_time = timer(NULL);

    record[cur_time + relative_timer] = callback;

    // insert to head if earlier than head's timer 
    if (cur_time + relative_time < current_timer) {
        current_timer = cur_time + relative_time;
        register_system_timer_callback(cur_time + relative_time, wrapper);
    }
}

~~~

## Similar problems

## Tags
DFS 
