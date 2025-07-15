import threading
import time


turn = 0
flag = [False, False]

def process_0():
    global turn, flag
    flag[0] = True
    turn = 1
    while flag[1] and turn == 1:
        
        pass
    
    print("Process 0 is in the critical section.")
    time.sleep(2)  
    
    flag[0] = False
    print("Process 0 exited the critical section.\n")

def process_1():
    global turn, flag
    flag[1] = True
    turn = 0
    while flag[0] and turn == 0:
    
        pass

    print("Process 1 is in the critical section.")
    time.sleep(1)  
    
    flag[1] = False
    print("Process 1 exited the critical section.\n")

if __name__ == "__main__":
    thread_0 = threading.Thread(target=process_0)
    thread_1 = threading.Thread(target=process_1)

    thread_0.start()
    thread_1.start()

    thread_0.join()
    thread_1.join()

    print("Both processes have completed.")