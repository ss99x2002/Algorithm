-- 중고거래의 총 금액이 70만원 이상인
-- 회원 id, 닉네임, 총거래 금액 조회 sql
-- 총거래금액 기준 오름차순 asc 
SELECT uu.user_id, uu.nickname, sum(ub.price) as total_sales
FROM used_goods_board as ub join used_goods_user as uu 
on ub.writer_id = uu.user_id
where ub.status = 'DONE'
GROUP BY uu.user_id
HAVING sum(ub.price) >= 700000
ORDER BY total_sales asc