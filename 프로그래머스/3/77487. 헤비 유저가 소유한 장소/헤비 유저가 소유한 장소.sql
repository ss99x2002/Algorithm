-- 서비스에 공간을 둘 이상 등록한 사람 => 헤비유저
-- 헤비유저가 등록한 공간의 정보
-- id순으로 sql 

WITH heavy_user as (
    SELECT HOST_ID
FROM PLACES
GROUP BY HOST_ID
HAVING COUNT(*) >=2 
ORDER BY HOST_ID ASC
)

SELECT p.id as id, p.name as name, p.host_id as host_id
FROM heavy_user as h LEFT JOIN PLACES as p
ON h.host_id = p.host_id
order by p.id asc 