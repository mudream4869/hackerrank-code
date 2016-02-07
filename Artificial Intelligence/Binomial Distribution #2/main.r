# The ratio of boys to girls born in Russia is 1.09:1.
# What proportion of Russian families with exactly 6 children will have at least 3 boys? (Ignore the probability of multiple births.)

ans <- 0
for(i in 3:6)
    ans <- ans + dbinom(i, 6, 1.09/(1+1.09))

cat(round(ans,digits = 3), "\n")