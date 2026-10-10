class Solution {
    public int maxEvents(int[][] events) {

        Arrays.sort(events, (a, b) -> {
            return Integer.compare(a[0], b[0]);
        });
        HashMap<Integer, PriorityQueue<Integer>> mpp = new HashMap<>();

        int currDay = events[0][0];
        int lastDay = currDay;

        for(int[] event : events)
        {
            int st = event[0];
            int end = event[1];

            lastDay = Math.max(end, lastDay);

            System.out.println(st + " " + end);
            mpp.computeIfAbsent(st, k -> new PriorityQueue<>()).add(end);
        }
        int attended = 0;

        PriorityQueue<Integer> allEvents = new PriorityQueue<>();
        System.out.println(currDay + " " + lastDay);
        while(currDay <= lastDay)
        {
            while(allEvents.isEmpty()==false && allEvents.peek() < currDay)allEvents.poll();

            PriorityQueue<Integer> it = mpp.get(currDay);
            while(it != null && it.isEmpty() == false)
            {
                allEvents.add(it.poll());
            }

            if(allEvents.isEmpty() == false)
            {
                allEvents.poll();
                attended++;
            }
            currDay++;
        }

        return attended;
    }
}

