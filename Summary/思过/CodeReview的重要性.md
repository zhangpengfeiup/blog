数据不一致，多了很多数据,最后在同事的CodeReview下找到了错误的地方:

```
foreach ($consume as $key => &$value) {
            foreach ($bidding as $k => $v) {
                if ($value['company_id'] == $v['company_id'] && $value['nslot'] == $value['nslot'] && $value['report_date'] == $value['report_date'] && $value['network'] == $v['network']) {
                    $value['adx_traffic'] = $v['adx_traffic'];
                    $value['company_bidding'] = $v['company_bidding'];
                    $value['adx_bidding'] = $v['adx_bidding'];
                }
            }
        }
```

其中 

```
$value['nslot'] == $value['nslot']
$value['report_date'] == $value['report_date']
```
所以导致最后多了很多数据，所以从这个问题上面说明CodeReview的重要性，有些很多小的问题，如果自己找的话需要找好久，所以也说明了团队合作的重要性。

关键词： CodeReview、小黄鸭找Bug、TeamWork