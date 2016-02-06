# The time taken to assemble a car in a certain plant is a random variable having a normal distribution with a mean of 20 hours and a standard deviation of 2 hours. What is the probability that a car can be assembled at this plant in:
# a) less than 19.5 hours?
# b) between 20 and 22 hours?

cat(round(
    pnorm(19.5, mean = 20, sd = 2, lower.tail = TRUE)
,digits = 3), "\n")

cat(round(
    pnorm(22, mean = 20, sd = 2) - pnorm(20, mean = 20, sd = 2)
,digits = 3), "\n")
