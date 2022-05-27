const counter = {
    number: 0,
    plus_one() {
        this.number++;
        return this;
    },
    minus_one() {
        this.number--;
        return this;
    },
    show_number() {
        console.log(this.number);
        return this;
    }
};

counter
  .plus_one()
  .plus_one()
  .plus_one()
  .minus_one()
  .show_number();