.PHONY: clean All

All:
	@echo "----------Building project:[ lin1d - Debug ]----------"
	@$(MAKE) -f  "lin1d.mk"
clean:
	@echo "----------Cleaning project:[ lin1d - Debug ]----------"
	@$(MAKE) -f  "lin1d.mk" clean
