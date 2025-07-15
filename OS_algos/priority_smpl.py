import functools

class Process:
    def __init__(self, processID, arrivalTime, priority, burstTime):
        self.processID = processID
        self.arrivalTime = arrivalTime
        self.priority = priority
        self.burstTime = burstTime
        self.tempburstTime = burstTime
        self.responsetime = -1
        self.outtime = 0
        self.intime = -1

# Function to insert a process into the heap
def insert(Heap, value, heapsize, currentTime):
    start = heapsize[0]
    Heap[start] = value
    if Heap[start].intime == -1:
        Heap[start].intime = currentTime
    heapsize[0] += 1

    # Ordering the Heap
    while start != 0 and Heap[(start - 1) // 2].priority > Heap[start].priority:
        Heap[(start - 1) // 2], Heap[start] = Heap[start], Heap[(start - 1) // 2]
        start = (start - 1) // 2

# Function to reorder the heap based on priority
def order(Heap, heapsize, start):
    smallest = start
    left = 2 * start + 1
    right = 2 * start + 2
    if left < heapsize[0] and Heap[left].priority < Heap[smallest].priority:
        smallest = left
    if right < heapsize[0] and Heap[right].priority < Heap[smallest].priority:
        smallest = right

    # Ordering the Heap
    if smallest != start:
        Heap[start], Heap[smallest] = Heap[smallest], Heap[start]
        order(Heap, heapsize, smallest)

# Function to extract the process with the highest priority from the heap
def extractminimum(Heap, heapsize, currentTime):
    min_process = Heap[0]
    if min_process.responsetime == -1:
        min_process.responsetime = currentTime - min_process.arrivalTime
    heapsize[0] -= 1
    if heapsize[0] >= 1:
        Heap[0] = Heap[heapsize[0]]
        order(Heap, heapsize, 0)
    return min_process

# Function to compare two processes based on arrival time
def compare(p1, p2):
    return p1.arrivalTime < p2.arrivalTime

# Function responsible for executing the highest priority process extracted from the heap
def scheduling(Heap, array, n, heapsize, currentTime):
    if heapsize[0] == 0:
        return

    min_process = extractminimum(Heap, heapsize, currentTime)
    min_process.outtime = currentTime + 1
    min_process.burstTime -= 1
    print(f"process id = {min_process.processID} current time = {currentTime}")

    # If the process is not yet finished, insert it back into the Heap
    if min_process.burstTime > 0:
        insert(Heap, min_process, heapsize, currentTime)
        return

    for i in range(n):
        if array[i].processID == min_process.processID:
            array[i] = min_process
            break

# Function responsible for managing the entire execution of processes based on arrival time
def priority(array, n):
    array.sort(key=lambda x: x.arrivalTime)

    total_waiting_time = 0
    total_burst_time = 0
    total_turnaround_time = 0
    inserted_process = 0
    heap_size = [0]
    current_time = array[0].arrivalTime  # Fix: No need to use a list for current_time
    total_response_time = 0

    Heap = [None] * (4 * n)

    # Calculating the total burst time of the processes
    for i in range(n):
        total_burst_time += array[i].burstTime
        array[i].tempburstTime = array[i].burstTime

    # Inserting the processes into Heap according to arrival time
    while True:
        if inserted_process != n:
            for i in range(n):
                if array[i].arrivalTime == current_time:
                    inserted_process += 1
                    array[i].intime = -1
                    array[i].responsetime = -1
                    insert(Heap, array[i], heap_size, current_time)
        scheduling(Heap, array, n, heap_size, current_time)
        current_time += 1  # Fix: Remove the list to avoid the TypeError
        if heap_size[0] == 0 and inserted_process == n:
            break

    for i in range(n):
        total_response_time += array[i].responsetime
        total_waiting_time += (array[i].outtime - array[i].intime - array[i].tempburstTime)
        total_turnaround_time += (array[i].outtime - array[i].intime)
        total_burst_time += array[i].burstTime

    print(f"Average waiting time = {total_waiting_time / n}")
    print(f"Average response time = {total_response_time / n}")
    print(f"Average turn around time = {total_turnaround_time / n}")

# Driver code
if __name__ == "__main__":
    n = 5
    a = [
        Process(1, 4, 2, 6),
        Process(4, 5, 1, 3),
        Process(2, 5, 3, 1),
        Process(3, 1, 4, 2),
        Process(5, 3, 5, 4)
    ]
    priority(a, n)

