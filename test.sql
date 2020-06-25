CREATE TABLE IF NOT EXISTS `test` (
id INTEGER PRIMARY KEY ASC,
LabNo VARCHAR NULL,
artifacts_no_and_ids VARCHAR NULL,
collectedBy VARCHAR NULL,
date VARCHAR NULL,
indirectSrc VARCHAR NULL,
material VARCHAR NULL,
materialId VARCHAR NULL,
materialType VARCHAR NULL,
site VARCHAR NULL,
srcId VARCHAR NULL,
srcType VARCHAR NULL,
standardError VARCHAR NULL,
submittedBy VARCHAR NULL);

INSERT INTO test(LabNo, artifacts_no_and_ids, collectedBy, date, indirectSrc, material, materialId, materialType, site, srcId, srcType, standardError, submittedBy) 
VALUES 
	('MTC-16147', 'Taisho3-P1', '', '11950', '3468', 'pottery - inside', '1', 'ps', 'Taisho 3 Site', '3468', 'a', '50', ''),
	('MTC-16148', 'Taisho3-P2', '', '12160', '3468', 'pottery - inside', '2', 'ps', 'Taisho 3 Site', '3468', 'a', '60', ''),
	('MTC-16149', 'Taisho3-P3', '', '12330', '3468', 'pottery - inside', '3', 'ps', 'Taisho 3 Site', '3468', 'a', '70', ''),
	('MTC-16150', 'Taisho3-P4', '', '12180', '3468', 'pottery - inside', '4', 'ps', 'Taisho 3 Site', '3468', 'a', '70', ''),
	('MTC-16151', 'Taisho3-P5', '', '12280', '3468', 'pottery - inside', '5', 'ps', 'Taisho 3 Site', '3468', 'a', '60', ''),
	('MTC-16152', 'Taisho3-P6', '', '11920', '3468', 'pottery - inside', '6', 'ps', 'Taisho 3 Site', '3468', 'a', '60', ''),
	('MTC-16153', 'YachiyoA-P14', '', '8160', '3468', 'pottery-inside,rim', '7', 'ps', 'Yachiyo A Site', '3468', 'a', '50', ''),
	('MTC-16154', 'YachiyoA-P19', '', '7920', '3468', 'pottery-inside,rim', '8', 'ps', 'Yachiyo A Site', '3468', 'a', '50', ''),
	('MTC-16155', 'YachiyoA-P20', '', '8000', '3468', 'pottery-inside,rim', '9', 'ps', 'Yachiyo A Site', '3468', 'a', '50', ''),
	('MTC-16156', 'YachiyoA-P21', '', '8190', '3468', 'pottery-inside,rim', '10', 'ps', 'Yachiyo A Site', '3468', 'a', '50', ''),
	('MTC-16157', 'YachiyoA-P22', '', '8130', '3468', 'pottery-inside,rim', '11', 'ps', 'Yachiyo A Site', '3468', 'a', '50', ''),
	('MTC-16158', 'YachiyoA-P23', '', '8430', '3468', 'pottery-inside,rim', '12', 'ps', 'Yachiyo A Site', '3468', 'a', '50', ''),
	('Tka-14586', 'KBM-F2-792', '', '12690', '3468', 'linear relief pottery', '13', 'ps', 'Kuboderaminami Site', '3468', 'a', '110', ''),
	('Tka-14587', 'KBM-IT-208', '', '12670', '3468', 'linear relief pottery', '14', 'ps', 'Kuboderaminami Site', '3468', 'a', '170', ''),
	('TKA-14598', 'KBM-F2-792', '', '12460', '3468', 'linear relief pottery', '15', 'ps', 'Kuboderaminami Site', '3468', 'a', '90', ''),
	('TKA-15463', 'KBM-G2-308', '', '12640', '3468', 'linear relief pottery', '16', 'ps', 'Kuboderaminami Site', '3468', 'a', '90', ''),
	('TKA-14554', 'KY-K-7-23-1', '', '11940', '3468', 'linear-relief', '17', 'ps', 'Komaruyama B Site', '3468', 'a', '50', ''),
	('TKA-14552', 'HY-32-1-1', '', '11800', '3468', 'pitted decoration pottery', '18', 'ps', 'Jin Site', '3468', 'a', '60', ''),
	('TKA-15459', 'HY-32-1-1', '', '11670', '3468', 'pitted decoration pottery', '19', 'ps', 'Jin Site', '3468', 'a', '80', ''),
	('TKA-15460', 'HY 32-1-1', '', '11690', '3468', 'pitted decoration pottery', '20', 'ps', 'Jin Site', '3468', 'a', '90', ''),
	('TKA-14594', '91 JE-614', '', '11700', '3468', 'pitted decoration pottery', '21', 'ps', 'Jin Site', '3468', 'a', '90', ''),
	('TKA-14599', 'HY 34', '', '11760', '3468', 'Nail-impressed pottery', '22', 'ps', 'Saigura Site', '3468', 'a', '120', ''),
	('TKA-15462', 'HY 37-2-1', '', '11760', '3468', 'Nail-impressed pottery', '23', 'ps', 'Saigura Site', '3468', 'a', '80', ''),
	('TKA-14584', 'HY 37-2-2', '', '11570', '3468', 'Nail-impressed pottery', '24', 'ps', 'Saigura Site', '3468', 'a', '80', ''),
	('TKA-14551', 'HY 37-1', '', '11550', '3468', 'Nail-impressed pottery', '25', 'ps', 'Saigura Site', '3468', 'a', '60', ''),
	('TKA-14556', '109', '', '11610', '3468', 'Plain pottery', '26', 'ps', 'Nakada D Site', '3468', 'a', '50', ''),
	('TKA-15461', '24T-24', '', '11440', '3468', 'Nail-impressed pottery', '27', 'ps', 'Nakada D Site', '3468', 'a', '80', ''),
	('TKA-14588', '2', '', '11340', '3468', 'Nail-impressed pottery', '28', 'ps', 'Nakada D Site', '3468', 'a', '120', ''),
	('TKA-14596', 'B4-16-3', '', '10740', '3468', 'Pressing and dragging', '29', 'ps', 'Okashimizu Site', '3468', 'a', '110', ''),
	('TKA-14597', 'B4-16-25', '', '10670', '3468', 'Pressing and dragging', '30', 'ps', 'Okashimizu Site', '3468', 'a', '140', ''),
	('TKA-14564', 'HY 83', '', '10510', '3468', 'Nail-impressed pottery', '31', 'ps', 'Kosegasawa Site', '3468', 'a', '60', ''),
	('TKA-14620', '14', '', '11070', '3468', 'Body Outer Type 1a', '32', 'ps', 'Unokiminami Site', '3468', 'a', '100', ''),
	('TKA-14611', '14', '', '10810', '3468', 'Body Inner Type 1a', '33', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14622', '241', '', '10920', '3468', 'Body Outer Type 1a', '34', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14623', '325', '', '10920', '3468', 'Body Outer Type 1b', '35', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14612', '325', '', '10860', '3468', 'Body Inner Type 1b', '36', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14591', '401', '', '10850', '3468', 'Body Outer Type 1c', '37', 'ps', 'Unokiminami Site', '3468', 'a', '130', ''),
	('TKA-14613', '2015', '', '10850', '3468', 'Rim Outer Type 1c', '38', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14624', '611', '', '10830', '3468', 'Body Outer Type 2a', '39', 'ps', 'Unokiminami Site', '3468', 'a', '80', ''),
	('TKA-14625', '613', '', '10900', '3468', 'Rim Outer Type 2a', '40', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14626', '613', '', '10880', '3468', 'Rim Inner Type 2a', '41', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14614', '614', '', '10790', '3468', 'Body Outer Type 2a', '42', 'ps', 'Unokiminami Site', '3468', 'a', '70', ''),
	('TKA-14581', '2021', '', '10990', '3468', 'Rim Outer Type 3b', '43', 'ps', 'Unokiminami Site', '3468', 'a', '80', ''),
	('TKA-14615', '2021', '', '11000', '3468', 'Rim Inner Type 3b', '44', 'ps', 'Unokiminami Site', '3468', 'a', '60', ''),
	('TKA-14582', '624', '', '10950', '3468', 'Rim Outer Type 5b', '45', 'ps', 'Unokiminami Site', '3468', 'a', '120', ''),
	('TKA-14616', '3001', '', '10990', '3468', 'Body Outer Type 7', '46', 'ps', 'Unokiminami Site', '3468', 'a', '60', ''),
	('TKA-14583', '3002', '', '11670', '3468', 'Rim Outer Type 7', '47', 'ps', 'Unokiminami Site', '3468', 'a', '130', '');