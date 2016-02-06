# X is a normally distributed variable with mean μ = 30 and standard deviation σ = 4. ind -
# a) P(x < 40)
# b) P(x > 21)
# c) P(30 < x < 35)

cat(round(pnorm(40, mean=30, sd=4), digits = 3), "\n")
cat(round(pnorm(21, mean=30, sd=4, lower.tail=FALSE), digits = 3), "\n")
cat(round(pnorm(30, mean=30, sd=4, lower.tail=FALSE) - pnorm(35, mean=30, sd=4, lower.tail=FALSE), digits = 3), "\n")
