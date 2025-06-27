-- python이나 c# 스킬 가진 개발자 정보 조회 (둘다 or 둘중 하나)

WITH python as (
    SELECT name, code
    FROM SKILLCODES
    WHERE name = 'Python'
), c_shop as (
    SELECT name, code
    FROM SKILLCODES
    WHERE name = 'C#'
)


SELECT d.id, d.email, d.first_name, d.last_name
FROM DEVELOPERS as d, python, c_shop
WHERE (d.skill_code & python.code ) >= 1 OR (d.skill_code & c_shop.code )
ORDER BY d.id asc




