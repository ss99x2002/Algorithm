-- 리뷰를 가장 많이 작성한 회원의 리뷰를 조회하는 SQL문
-- 회원 이름, 리뷰 텍스트, 리뷰 작성일 출력
-- 리뷰 작성일 기준 오름차순, 리뷰 텍스트 기준 오름차순
SELECT mp.member_name, rr.review_text, CAST(DATE(rr.review_date) as CHAR) as review_date
FROM member_profile as mp join rest_review as rr on mp.member_id = rr.member_id
WHERE rr.member_id = (
    Select member_id
    from rest_review
    Group by member_id
    order by Count(*) DESC
    LImit 1
)
ORDER BY rr.review_date ASC, rr.review_text ASC