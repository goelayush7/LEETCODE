SELECT E.name
FROM Employee E
JOIN Employee E1 ON E.id = E1.managerId
GROUP BY E.id
HAVING COUNT(E1.id) >= 5;
