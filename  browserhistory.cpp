#include "browserhistory.h"


BrowserHistory::BrowserHistory(string default_url) {
    past.push(default_url);                                     //Setting default_url to the first block of the stack
}

string BrowserHistory::current_url() {
    return past.top();                                        //Returns the last url which is the current_url
}

void BrowserHistory::go_to_url(string url) {
    past.push(url);                                             //Inset a URL to the top of the stack
    while (!future.empty()){                                    //Checks if future stack has any urls
        future.pop();                                           // Removes the url that was saved to go forward
    }
}



void BrowserHistory::back() {
    if(can_go_back()) {                                         //Checks if we have a page to go back
        future.push(past.top());                              //The top url on the past stack is identified then inserted to the top of the future stack
        past.pop();                                             //Deletes the item on the past stack
    }
}
void BrowserHistory::forward() {
    if(can_go_forward()) {                                      //Checks if we have a page to go forward
        past.push(future.top());                              //The top url on the future stack is identified then inserted to the top of the past stack
        future.pop();                                           //Deletes the item on the future stack
    }
}





bool BrowserHistory::can_go_back() {
    return past.size() > 1;                                      //Returns the size of past stack and checks if its greater than 1
}
bool BrowserHistory::can_go_forward() {
    return future.size() > 0;                                    //Returns the size of future stack and checks if its greater than 0
}





int BrowserHistory::past_url_count() {
    return past.size() - 1;                                       //Returns the size of past size minus the current url
}
int BrowserHistory::future_url_count() {
    return future.size();                                         //Returns the size of future stack
}






