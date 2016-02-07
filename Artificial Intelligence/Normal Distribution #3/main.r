# A large group of students took a test in physics and the final grades have a mean of 70 and a standard deviation of 10. If we can approximate the distribution of these grades by a normal distribution, what percent of the students
# a) scored higher than 80?
# b) should pass the test (grades≥60)?
# c) should fail the test (grades<60)?
cat(round(
    pnorm(80, mean = 70, sd = 10, lower.tail = FALSE)*100
, digits = 2), "\n")

cat(round(
    pnorm(60, mean = 70, sd = 10, lower.tail = FALSE)*100
, digits = 2), "\n")

cat(round(
    pnorm(60, mean = 70, sd = 10)*100
, digits = 2), "\n")