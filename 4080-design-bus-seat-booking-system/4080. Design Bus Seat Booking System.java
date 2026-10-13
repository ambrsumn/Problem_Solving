class BusBooking {

    HashMap<String, Integer> seats;
    int totalTime;

    public BusBooking(int n) {
        this.totalTime = 0;
        this.seats = new HashMap<>();
    }

    public void toggle(String seat) {

        if (seats.containsKey(seat)) {
            this.totalTime -= seats.get(seat);
            this.seats.remove(seat);

            // IO.println(seat + " --- " + this.totalTime);

            return;
        }

        char col = seat.charAt(0);

        if (col == 'A' || col == 'D') {

            StringBuilder adjacentSeat = new StringBuilder(seat);
            if (col == 'D')
                adjacentSeat.setCharAt(0, 'C');
            if (col == 'A')
                adjacentSeat.setCharAt(0, 'B');

            // IO.println(seat + " " + adjacentSeat);
            // IO.println(this.seats);

            if (seats.containsKey(adjacentSeat.toString())) {
                this.totalTime += 3;
                this.seats.put(seat, 3);

                return;
            }
        }

        this.totalTime += 1;
        this.seats.put(seat, 1);

            // IO.println(seat + " --- " + this.totalTime);

        return;
    }

    public int getTotalTime() {

        return this.totalTime;
    }

    public int getMinTime() {

        return this.seats.size();

    }
}

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking obj = new BusBooking(n);
 * obj.toggle(seat);
 * int param_2 = obj.getTotalTime();
 * int param_3 = obj.getMinTime();
 */