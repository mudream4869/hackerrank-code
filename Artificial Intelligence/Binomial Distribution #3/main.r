# A manufacturer of metal pistons finds that on average, 12% of his pistons are rejected because they are either oversized or undersized. What is the probability that a batch of 10 pistons will contain
# (a) no more than 2 rejects?
# (b) at least 2 rejects?

print <- function(value){
    cat(round(value, digits = 3), "\n")
}

print(sum(dbinom(0:2, 10, 0.12)))
print(sum(dbinom(2:10, 10, 0.12)))