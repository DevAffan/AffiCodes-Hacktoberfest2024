class Job:
    def __init__(self, job_id, deadline, profit):
        self.job_id = job_id
        self.deadline = deadline
        self.profit = profit

def job_scheduling(jobs):
    # Sort jobs by decreasing order of profit
    jobs.sort(key=lambda x: x.profit, reverse=True)

    n = len(jobs)
    result = [None] * n  # To store the result of jobs
    slot = [False] * n   # To keep track of free time slots

    total_profit = 0

    # Iterate through all jobs
    for job in jobs:
        # Find a free slot for this job (starting from the last possible slot)
        for j in range(min(n, job.deadline) - 1, -1, -1):
            if not slot[j]:
                slot[j] = True
                result[j] = job.job_id
                total_profit += job.profit
                break

    return result, total_profit

# Example usage
if __name__ == "__main__":
    jobs = [Job('A', 2, 100), Job('B', 1, 19), Job('C', 2, 27), Job('D', 1, 25), Job('E', 3, 15)]

    scheduled_jobs, total_profit = job_scheduling(jobs)
    
    print("Scheduled Jobs:", scheduled_jobs)
    print("Total Profit:", total_profit)
