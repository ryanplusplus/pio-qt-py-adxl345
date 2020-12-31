.PHONY: all
all:
	@pio run

.PHONY: upload
upload:
	@pio run -t upload

.PHONY: run
run: upload
	@pio run -t monitor

.PHONY: monitor
monitor:
	@pio run -t monitor

.PHONY: clean
clean:
	@pio run -t clean

.PHONY: test
test:
	@$(MAKE) --no-print-directory -f test.mk
